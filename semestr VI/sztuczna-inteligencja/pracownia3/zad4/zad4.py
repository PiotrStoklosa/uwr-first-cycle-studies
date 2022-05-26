def B(i, j):
    return 'B_%d_%d' % (i, j)


def field(i, j):
    return 'B_%d_%d in 0..1' % (i, j)


def write_row_sum():
    return ',\n'.join(
        [' + '.join([B(i, k) for k in range(len(cols))]) + ' #= ' + str(rows[i]) for i in range(len(rows))]) + ','


def write_cols_sum():
    return ',\n'.join(
        [' + '.join([B(k, i) for k in range(len(rows))]) + ' #= ' + str(cols[i]) for i in range(len(cols))]) + ','


def write_triples():
    return ',\n'.join(
        [B(t[0], t[1]) + ' #= ' + str(t[2]) for t in triples]) + ','


def write_triples_in_row():
    return ',\n'.join(
        [', '.join(
            [B(i, j) + ' + 2 * ' + B(i, j + 1) + ' + 3 * ' + B(i, j + 2) + ' #\= 2' for j in range(len(cols) - 2)]) for
            i
            in range(len(rows))]) + ','


def write_triples_in_columns():
    return ',\n'.join(
        [', '.join(
            [B(j, i) + ' + 2 * ' + B(j + 1, i) + ' + 3 * ' + B(j + 2, i) + ' #\= 2' for j in range(len(rows) - 2)]) for
            i
            in range(len(cols))]) + ','


def write_rectangles():
    return ',\n'.join(
        [', '.join(
            [B(i, j) + ' * ' + B(i + 1, j + 1) + ' + ' + B(i + 1, j) + ' * ' + B(i, j + 1) + ' #\= 1' for j in
             range(len(rows) - 1)]) for
            i
            in range(len(cols) - 1)]) + ','


def storms():
    writeln(':- use_module(library(clpfd)).')

    R = len(rows)
    C = len(cols)

    bs = [B(i, j) for i in range(R) for j in range(C)]
    f = [field(i, j) for i in range(R) for j in range(C)]

    writeln('solve([' + ', '.join(bs) + ']) :- ')
    writeln(', '.join(f) + ',')
    writeln(write_row_sum() + '\n')
    writeln(write_cols_sum() + '\n')
    writeln(write_triples() + '\n')
    writeln(write_triples_in_row() + '\n')
    writeln(write_triples_in_columns() + '\n')
    writeln(write_rectangles())

    writeln('    labeling([ff], [' + ', '.join(bs) + ']).')
    writeln('')
    writeln(":- solve(X), write(X), nl, told.")


def writeln(s):
    output.write(s + '\n')


txt = open('zad_input.txt').readlines()
output = open('zad_output.pl', 'w')

rows = list(map(int, txt[0].split()))
cols = list(map(int, txt[1].split()))
triples = []

for i in range(2, len(txt)):
    if txt[i].strip():
        triples.append(list(map(int, txt[i].split())))

storms()
