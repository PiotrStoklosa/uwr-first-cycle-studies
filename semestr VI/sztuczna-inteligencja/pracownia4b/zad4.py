from random import randrange

import chess
import chess.engine

infinity = 1000000
alpha_product = 1
engine = chess.engine.SimpleEngine.popen_uci("stockfish_15_x64_avx2.exe")


def stockfish_evaluation(board, time_limit=0.001):
    return engine.analyse(board, chess.engine.Limit(time=time_limit))['score'].relative


def value(piece_type):
    if piece_type == chess.QUEEN:
        return 9
    if piece_type == chess.ROOK:
        return 5
    if piece_type == chess.BISHOP or piece_type == chess.KNIGHT:
        return 3
    if piece_type == chess.PAWN:
        return 1
    return 0


def note_position(chess_board, side):
    if chess_board.is_checkmate():
        return 1000000
    if chess_board.is_stalemate():
        return 0
    black_move(chess_board)
    points = len(list(chess_board.legal_moves))
    chess_board.turn = chess.BLACK
    points -= len(list(chess_board.legal_moves))
    chess_board.turn = chess.WHITE
    points *= alpha_product
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


def black_move(board):
    moves = list(board.legal_moves)
    rand = randrange(len(moves))
    board.push(moves[rand])


def white_move(board):
    points = -1000
    best_move = "e1e2"

    for move in list(board.legal_moves):
        board.push(move)
        note = note_position(board, chess.WHITE)
        if note > points:
            points = note
            best_move = board.pop()
        else:
            board.pop()

    board.push(best_move)


def play(alpha):
    global alpha_product
    alpha_product = alpha
    board = chess.Board()
    for move in range(100):
        white_move(board)
        if board.is_checkmate():
            return 100
        if board.is_stalemate():
            return -100
        black_move(board)
        if board.is_checkmate():
            return -1000
        if board.is_stalemate():
            return -100
    return -100


def white_move_engine(board, time_limit):
    board.push(engine.play(board, chess.engine.Limit(time=time_limit)).move)


def play_engine(time_limit):
    board = chess.Board()
    for move in range(100):
        white_move_engine(board, time_limit)
        if board.is_checkmate():
            return 100
        if board.is_stalemate():
            return -100
        black_move(board)
        if board.is_checkmate():
            return -1000
        if board.is_stalemate():
            return -100
    return -100


sum_of_points_my_algorithm = 0
for i in range(10):
    sum_of_points_my_algorithm += play(0.02)

sum_of_points_stockfish = 0

for i in range(10):
    sum_of_points_stockfish += play_engine(0.01)

print("Result after 10 games by my algorithm: " + str(sum_of_points_my_algorithm))
print("Result after 10 games by stockfish: " + str(sum_of_points_stockfish))
