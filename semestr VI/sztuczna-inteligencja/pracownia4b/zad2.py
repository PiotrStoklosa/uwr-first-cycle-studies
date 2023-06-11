from random import randrange

import chess
import chess.engine
from chess.engine import Cp

infinity = 1000000
alpha_product_white = 1
alpha_product_black = 1
result = [0] * 104
engine = chess.engine.SimpleEngine.popen_uci("stockfish_15_x64_avx2.exe")


def stockfish_evaluation(board, time_limit=0.001):
    return engine.analyse(board, chess.engine.Limit(time=time_limit))['score'].relative


# def value(piece_type):
#     if piece_type == chess.QUEEN:
#         return 9
#     if piece_type == chess.ROOK:
#         return 5
#     if piece_type == chess.BISHOP or piece_type == chess.KNIGHT:
#         return 3
#     if piece_type == chess.PAWN:
#         return 1
#     return 0

def value(piece_type):
    if piece_type == chess.QUEEN:
        return randrange(10)
    if piece_type == chess.ROOK:
        return randrange(10)
    if piece_type == chess.BISHOP or piece_type == chess.KNIGHT:
        return randrange(10)
    if piece_type == chess.PAWN:
        return randrange(10)
    return 0


def note_position(chess_board, side):
    if chess_board.is_checkmate():
        return 1000000
    if chess_board.is_stalemate():
        return 0
    random_move(chess_board)
    points = len(list(chess_board.legal_moves))
    if side == chess.WHITE:
        chess_board.turn = chess.BLACK
    else:
        chess_board.turn = chess.WHITE
    points -= len(list(chess_board.legal_moves))
    chess_board.turn = side
    if side == chess.WHITE:
        points *= alpha_product_white
    if side == chess.BLACK:
        points *= alpha_product_black
    black_value = 0
    white_value = 0
    for field in list(chess_board.piece_map()):
        piece = chess_board.piece_at(field)
        piece_type = piece.piece_type
        piece_color = piece.color

        if piece_color == side:
            white_value += value(piece_type)
        else:
            black_value += value(piece_type)
    chess_board.pop()
    return points


def random_move(board):
    moves = list(board.legal_moves)
    rand = randrange(len(moves))
    board.push(moves[rand])


def white_move(board, color):
    points = -1000
    best_move = "e1e2"

    for move in list(board.legal_moves):
        board.push(move)
        note = note_position(board, color)
        if note > points:
            points = note
            best_move = board.pop()
        else:
            board.pop()

    board.push(best_move)


def calculate_points(board):
    res = stockfish_evaluation(board)
    if res == Cp(0):
        return "STALEMATE"
    if res < Cp(0):
        return "BLACK"
    return "WHITE"


def play(alpha_white, alpha_black):
    global alpha_product_white
    global alpha_product_black
    alpha_product_white = alpha_white
    alpha_product_black = alpha_black
    board = chess.Board()
    for move in range(100):
        white_move(board, chess.WHITE)
        if board.is_checkmate():
            return "WHITE"
        if board.is_stalemate():
            return "STALEMATE"
        white_move(board, chess.BLACK)
        if board.is_checkmate():
            return "BLACK"
        if board.is_stalemate():
            return "STALEMATE"
    return calculate_points(board)


sum_of_points = 0
for i in range(1, 31):
    for j in range(i + 1, 31):
        print("Competition between: " + str(i / 100) + " and " + str(j / 100))
        match_result = play(i / 100, j / 100)
        if match_result == "WHITE":
            result[i] += 1
        elif match_result == "BLACK":
            result[j] += 1

dictionary = {}
output = open("result.txt", "w")
for i in range(1, 31):
    dictionary[i] = result[i]

dictionary = sorted(dictionary.items(), key=lambda x: x[1], reverse=True)
for i in dictionary:
    output.write(str(i[0] / 100) + " " + str(i[1]) + '\n')

output.close()
exit(0)
