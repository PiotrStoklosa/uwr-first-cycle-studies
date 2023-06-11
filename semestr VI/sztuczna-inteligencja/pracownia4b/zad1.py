from random import randrange

import chess

infinity = 1000000
alpha_product = 1


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
    random_move(chess_board)
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


def random_move(board):
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
        random_move(board)
        if board.is_checkmate():
            return -1000
        if board.is_stalemate():
            return -100
    return -100


sum_of_points = 0
for i in range(50):
    sum_of_points += play(0.02)

print("Result after 50 games: " + str(sum_of_points))
