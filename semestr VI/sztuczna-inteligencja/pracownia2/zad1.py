inputFile = open("zad_input.txt")
outputFile = open("zad_output.txt", "w")

first_line = True
size_row = 0
size_column = 0
rows = []
columns = []
row_counter = 0
possible_rows = []
possible_columns = []


def check_certain(line, line_size):
    results = []
    if line_size == 0:
        return [""]
    if not line:
        return ["." * line_size]
    for i in range(line_size - sum(line) - len(line) + 2):
        last_dot = 1
        if line[0] == line_size - i:
            last_dot = 0
        recursive_results = check_certain(line[1:], line_size - i - line[0] - last_dot)
        for recursive_result in recursive_results:
            results.append("." * i + "#" * line[0] + "." * last_dot + recursive_result)
    return results


for field in inputFile:
    if first_line:
        size = field.split()
        size_row = int(size[0])
        size_column = int(size[1])
        first_line = False
    else:
        if row_counter < size_row:
            rows.append(field.strip())
            row_counter += 1
        else:
            columns.append(field.strip())

for field in rows:
    possible_rows.append(check_certain(list(map(int, field.split())), size_row))
for field in columns:
    possible_columns.append(check_certain(list(map(int, field.split())), size_column))


def create_queue(items):
    return [item for item in range(items)]


queue = create_queue(size_row * size_column)
image = [["." for i in range(size_column)] for j in range(size_row)]

while queue:
    field = queue.pop(0)
    row_number = field // size_column
    column_number = field % size_row
    dots = 0
    hashes = 0
    for combination in possible_rows[row_number]:
        if combination[column_number] == "#":
            hashes += 1
        else:
            dots += 1
    if dots == 0 or hashes == 0:
        if dots == 0:
            image[row_number][column_number] = "#"
        new_combinations = []
        for col in possible_columns[column_number]:
            if col[row_number] == image[row_number][column_number]:
                new_combinations.append(col)
        possible_columns[column_number] = new_combinations
    else:
        dots = 0
        hashes = 0
        for combination in possible_columns[column_number]:
            if combination[row_number] == "#":
                hashes += 1
            else:
                dots += 1
        if dots == 0 or hashes == 0:
            if dots == 0:
                image[row_number][column_number] = "#"
            new_combinations = []
            for r in possible_rows[row_number]:
                if r[column_number] == image[row_number][column_number]:
                    new_combinations.append(r)
            possible_rows[row_number] = new_combinations
        else:
            queue.append(field)

for field in image:
    for j in field:
        outputFile.write(str(j))
    outputFile.write('\n')

inputFile.close()
outputFile.close()
