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
        size_column = int(size[0])
        size_row = int(size[1])
        first_line = False
    else:
        if row_counter < size_column:
            rows.append(field.strip())
            row_counter += 1
        else:
            columns.append(field.strip())

for field in rows:
    possible_rows.append(check_certain(list(map(int, field.split())), size_row))
for field in columns:
    possible_columns.append(check_certain(list(map(int, field.split())), size_column))

image = [["X" for i in range(size_row)] for j in range(size_column)]


def short_rows(i, j, val):
    result = False
    new_possible_rows = []
    for row in possible_rows[i]:
        if row[j] == val:
            new_possible_rows.append(row)
        else:
            result = True
    possible_rows[i] = new_possible_rows
    return result


def short_columns(i, j, val):
    result = False
    new_possible_columns = []
    for column in possible_columns[j]:
        if column[i] == val:
            new_possible_columns.append(column)
        else:
            result = True
    possible_columns[j] = new_possible_columns
    return result


def check():
    res = False
    for i in range(size_column):
        for j in range(size_row):
            if image[i][j] != 'X':
                res = res or short_rows(i, j, image[i][j]) or short_columns(i, j, image[i][j])
    return res


def test_equivalence():
    res = False
    for i in range(size_column):
        for j in range(size_row):
            if image[i][j] == 'X':
                hashes = 0
                dots = 0
                for row in possible_rows[i]:
                    if row[j] == "#":
                        hashes += 1
                    else:
                        dots += 1
                if dots == 0 or hashes == 0:
                    res = True
                    if dots == 0:
                        image[i][j] = '#'
                    else:
                        image[i][j] = '.'
                else:
                    hashes = 0
                    dots = 0
                    for column in possible_columns[j]:
                        if column[i] == "#":
                            hashes += 1
                        else:
                            dots += 1
                    if dots == 0 or hashes == 0:
                        res = True
                        if dots == 0:
                            image[i][j] = '#'
                        else:
                            image[i][j] = '.'
    return res


def resolve():
    inference = True
    while inference:
        inference = check()
        inference = inference or test_equivalence()
    for row in image:
        for row_field in row:
            outputFile.write(str(row_field))
        outputFile.write('\n')


resolve()

inputFile.close()
outputFile.close()
