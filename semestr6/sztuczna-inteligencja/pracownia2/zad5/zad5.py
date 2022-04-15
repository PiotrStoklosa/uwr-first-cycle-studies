from queue import PriorityQueue

inputFile = open("zad_input.txt")
outputFile = open("zad_output.txt", "w")

game = []
states = set()

nearest_goals_map = []

for line in inputFile:

    game.append(line.strip())
    nearest_goals_map.append([-1 for i in range(len(line.strip()))])
rows = len(game)
columns = len(game[0])


def legal_move(x, y, visited):
    return not (x < 0 or x >= rows or y < 0 or y >= columns or visited[x][y] or game[x][y] == "#")


def bfs(x, y):
    visited = [[False for i in range(columns)] for j in range(rows)]
    queue = [(x, y, 0)]
    while queue:
        current = queue.pop(0)
        visited[current[0]][current[1]] = True
        if game[current[0]][current[1]] == "B" or game[current[0]][current[1]] == "G":
            return current[2]
        if legal_move(current[0] + 1, current[1], visited):
            queue.append((current[0] + 1, current[1], current[2] + 1))
        if legal_move(current[0] - 1, current[1], visited):
            queue.append((current[0] - 1, current[1], current[2] + 1))
        if legal_move(current[0], current[1] + 1, visited):
            queue.append((current[0], current[1] + 1, current[2] + 1))
        if legal_move(current[0], current[1] - 1, visited):
            queue.append((current[0], current[1] - 1, current[2] + 1))


def search_nearest_goals():
    for i in range(rows):
        for j in range(columns):
            if game[i][j] != "#":
                nearest_goals_map[i][j] = bfs(i, j)


def count_priority(started_points):
    max_distance = 0
    for point in started_points:
        if nearest_goals_map[point[0]][point[1]] > max_distance:
            max_distance = nearest_goals_map[point[0]][point[1]]
    return max_distance


search_nearest_goals()


def move_up(starting_positions):
    new_positions = set()
    for pos in starting_positions:
        if game[pos[0] - 1][pos[1]] == "#":
            new_positions.add((pos[0], pos[1]))
        else:
            new_positions.add((pos[0] - 1, pos[1]))
    return new_positions


def move_right(starting_positions):
    new_positions = set()
    for pos in starting_positions:
        if game[pos[0]][pos[1] + 1] == "#":
            new_positions.add((pos[0], pos[1]))
        else:
            new_positions.add((pos[0], pos[1] + 1))
    return new_positions


def move_down(starting_positions):
    new_positions = set()
    for pos in starting_positions:
        if game[pos[0] + 1][pos[1]] == "#":
            new_positions.add((pos[0], pos[1]))
        else:
            new_positions.add((pos[0] + 1, pos[1]))
    return new_positions


def move_left(starting_positions):
    new_positions = set()
    for pos in starting_positions:
        if game[pos[0]][pos[1] - 1] == "#":
            new_positions.add((pos[0], pos[1]))
        else:
            new_positions.add((pos[0], pos[1] - 1))
    return new_positions


def play():
    starting_positions = []
    for i in range(len(game)):
        for j in range(len(game[i])):
            if game[i][j] == "S" or game[i][j] == "B":
                starting_positions.append((i, j))
    q = PriorityQueue()
    q.put((count_priority(starting_positions), tuple(starting_positions), 0))
    while q:
        current = q.get()
        if count_priority(current[1]) == 0:
            return current[2]
        states.add(tuple(current[1]))
        mv_left = move_left(current[1])
        mv_up = move_up(current[1])
        mv_right = move_right(current[1])
        mv_down = move_down(current[1])
        if tuple(mv_left) not in states:
            q.put((count_priority(mv_left) + current[2] + 1, mv_left, current[2] + 1))
        if tuple(mv_up) not in states:
            q.put((count_priority(mv_up) + current[2] + 1, mv_up, current[2] + 1))
        if tuple(mv_right) not in states:
            q.put((count_priority(mv_right) + current[2] + 1, mv_right, current[2] + 1))
        if tuple(mv_down) not in states:
            q.put((count_priority(mv_down) + current[2] + 1, mv_down, current[2] + 1))


print(play())
# for i in range(len(game)):
#     for j in range (len(game[0])):
#         print(nearest_goals_map[i][j], end=' ')
#     print()


inputFile.close()
outputFile.close()
