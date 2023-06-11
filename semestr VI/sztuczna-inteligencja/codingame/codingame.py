position = []

field_converter = {"a": 1, "b": 2, "c": 3, "d": 4, "e": 5, "f": 6, "g": 7, "h": 8}
reverse_field_convert = {1: "a", 2: "b", 3: "c", 4: "d", 5: "e", 6: "f", 7: "g", 8: "h"}

MOVE = 0
WHITE_KING = 1
WHITE_ROOK = 2
BLACK_KING = 3
HISTORY = 4

X = 0
Y = 1

visited_state = {""}


def create_queue_entry(move, white_king, white_rook, black_king, history):
    return [move, white_king, white_rook, black_king, history]


def create_history_entry(current_position):
    return current_position[:4]


def on_board(field):
    return 1 <= field[X] <= 8 and 1 <= field[Y] <= 8


def is_white_king_legal_move(field, current_position):
    return on_board(field) and not (abs(field[X] - current_position[BLACK_KING][X]) <= 1 and abs(
        field[Y] - current_position[BLACK_KING][Y]) <= 1) and not (
            field[X] == current_position[WHITE_ROOK][X] and field[Y] == current_position[WHITE_ROOK][Y]) \
           and not (
                           "black " + str(
                       reverse_field_convert[
                           field[
                               X]]) + str(
                       field[
                           Y]) + " " + str(
                       reverse_field_convert[
                           current_position[
                               WHITE_ROOK][
                               X]]) + str(
                       current_position[
                           WHITE_ROOK][
                           Y]) + " " +
                           reverse_field_convert[
                               current_position[
                                   BLACK_KING][
                                   X]] + str(
                       current_position[
                           BLACK_KING][
                           Y])) in visited_state


def is_white_rook_legal_move(field, current_position, sort):
    return on_board(field) and not (
            current_position[WHITE_ROOK][abs(1 - sort)] == current_position[WHITE_KING][abs(1 - sort)] and (
            current_position[WHITE_ROOK][sort] <= current_position[WHITE_KING][sort] <= field[sort] or
            current_position[WHITE_ROOK][sort] >= current_position[WHITE_KING][sort] >= field[sort])) \
           and not (
                           "black " + str(
                       reverse_field_convert[
                           current_position[
                               WHITE_KING][
                               X]]) + str(
                       current_position[
                           WHITE_KING][
                           Y]) + " " + str(
                       reverse_field_convert[
                           field[
                               X]]) + str(
                       field[
                           Y]) + " " +
                           reverse_field_convert[
                               current_position[
                                   BLACK_KING][
                                   X]] + str(
                       current_position[
                           BLACK_KING][
                           Y])) in visited_state


def is_black_king_legal_move(field, current_position):
    return on_board(field) and not (abs(field[X] - current_position[WHITE_KING][X]) <= 1 and abs(
        field[Y] - current_position[WHITE_KING][Y]) <= 1 or field[X] == current_position[WHITE_ROOK][X] or field[
                                        Y] == current_position[WHITE_ROOK][Y]) \
           and not ("white " + str(
        reverse_field_convert[current_position[WHITE_KING][X]]) + str(
        current_position[WHITE_KING][Y]) + " " + str(
        reverse_field_convert[current_position[WHITE_ROOK][X]]) + str(
        current_position[WHITE_ROOK][Y]) + " " + reverse_field_convert[field[X]] + str(
        field[Y])) in visited_state


def is_black_king_legal_move_for_checkmate(field, current_position):
    return on_board(field) and not (abs(field[X] - current_position[WHITE_KING][X]) <= 1 and abs(
        field[Y] - current_position[WHITE_KING][Y]) <= 1 or field[X] == current_position[WHITE_ROOK][X] or field[
                                        Y] == current_position[WHITE_ROOK][Y])


def is_black_king_checked(current_position):
    return current_position[BLACK_KING][X] == current_position[WHITE_ROOK][X] or current_position[BLACK_KING][Y] == \
           current_position[WHITE_ROOK][Y]


def make_move_white_king(field, current_position):
    visited_state.add("black " + str(reverse_field_convert[field[X]]) + str(field[Y]) + " " + str(
        reverse_field_convert[current_position[WHITE_ROOK][X]]) + str(
        current_position[WHITE_ROOK][Y]) + " " + reverse_field_convert[current_position[BLACK_KING][X]] + str(
        current_position[BLACK_KING][Y]))

    current_position_history = current_position[HISTORY].copy()
    current_position_history.append(
        reverse_field_convert[current_position[WHITE_KING][X]] + str(current_position[WHITE_KING][Y]) +
        reverse_field_convert[field[X]] + str(field[Y]))
    return create_queue_entry("b", field, current_position[WHITE_ROOK], current_position[BLACK_KING],
                              current_position_history)


def make_move_black_king(field, current_position):
    visited_state.add("white " + str(reverse_field_convert[current_position[WHITE_KING][X]]) + str(
        current_position[WHITE_KING][Y]) + " " + str(
        reverse_field_convert[current_position[WHITE_ROOK][X]]) + str(
        current_position[WHITE_ROOK][Y]) + " " + reverse_field_convert[field[X]] + str(
        field[Y]))

    current_position_history = current_position[HISTORY].copy()
    current_position_history.append(
        reverse_field_convert[current_position[BLACK_KING][X]] + str(current_position[BLACK_KING][Y]) +
        reverse_field_convert[field[X]] + str(field[Y]))
    return create_queue_entry("w", current_position[WHITE_KING], current_position[WHITE_ROOK], field,
                              current_position_history)


def make_move_white_rook(field, current_position):
    visited_state.add("black " + str(reverse_field_convert[current_position[WHITE_KING][X]]) + str(
        current_position[WHITE_KING][Y]) + " " + str(
        reverse_field_convert[field[X]]) + str(
        field[Y]) + " " + reverse_field_convert[current_position[BLACK_KING][X]] + str(
        current_position[BLACK_KING][Y]))

    current_position_history = current_position[HISTORY].copy()
    current_position_history.append(
        reverse_field_convert[current_position[WHITE_ROOK][X]] + str(current_position[WHITE_ROOK][Y]) +
        reverse_field_convert[field[X]] + str(field[Y]))
    return create_queue_entry("b", current_position[WHITE_KING], field, current_position[BLACK_KING],
                              current_position_history)


def is_checkmate(current_position):
    if is_black_king_checked(current_position):
        for i in range(-1, 2):
            for j in range(-1, 2):
                if i != 0 or j != 0:
                    new_black_king_X = current_position[BLACK_KING][X] + i
                    new_black_king_Y = current_position[BLACK_KING][Y] + j
                    if is_black_king_legal_move_for_checkmate([new_black_king_X, new_black_king_Y],
                                                              current_position) or \
                            current_position[WHITE_ROOK] == [new_black_king_X, new_black_king_Y]:
                        return False
        return True
    return False


def print_history(current_position):
    result = ""
    for text in current_position[HISTORY]:
        result += text + " "
    print(result[:-1])


def play():
    while position:
        current_position = position.pop(0)
        legal_positions = []
        if current_position[MOVE] == "b":
            for i in range(-1, 2):
                for j in range(-1, 2):
                    if i != 0 or j != 0:
                        new_black_king_X = current_position[BLACK_KING][X] + i
                        new_black_king_Y = current_position[BLACK_KING][Y] + j
                        if not current_position[WHITE_ROOK] == [new_black_king_X,
                                                                new_black_king_Y] and is_black_king_legal_move(
                            [new_black_king_X, new_black_king_Y], current_position):
                            legal_positions.append(make_move_black_king(
                                [new_black_king_X, new_black_king_Y], current_position))
        else:
            for i in range(-1, 2):
                for j in range(-1, 2):
                    if i != 0 or j != 0:
                        new_white_king_X = current_position[WHITE_KING][X] + i
                        new_white_king_Y = current_position[WHITE_KING][Y] + j
                        if is_white_king_legal_move([new_white_king_X, new_white_king_Y], current_position):
                            legal_positions.append(make_move_white_king(
                                [new_white_king_X, new_white_king_Y], current_position))

            current_rook_X = current_position[WHITE_ROOK][X]
            current_rook_Y = current_position[WHITE_ROOK][Y]

            for i in [1, 8]:
                if i != current_rook_X and is_white_rook_legal_move([i, current_rook_Y], current_position, 0):
                    new_position = make_move_white_rook([i, current_rook_Y], current_position)
                    legal_positions.append(new_position)
                    if is_checkmate(new_position):
                        print_history(new_position)
                        return

            for i in [1, 8]:
                if i != current_rook_Y and is_white_rook_legal_move([current_rook_X, i], current_position, 1):
                    new_position = make_move_white_rook([current_rook_X, i], current_position)
                    legal_positions.append(new_position)
                    if is_checkmate(new_position):
                        print_history(new_position)
                        return
        for legal_position in legal_positions:
            position.append(legal_position)
        if not position:
            print("INF")
            return


line = input()
position.append(
    create_queue_entry(line[0], [field_converter[line[6]], int(line[7])], [field_converter[line[9]], int(line[10])],
                       [field_converter[line[12]], int(line[13])],
                       []))

play()
