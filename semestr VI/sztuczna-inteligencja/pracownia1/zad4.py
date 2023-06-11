wy = open("zad4_output.txt", "w")
we = open("zad4_input.txt")


def count_zeros(sequence):
    return sequence.count('0')


def count_ones(sequence):
    return sequence.count('1')


def opt_dist(sequence, D):
    max_change = len(sequence)
    length_seq = len(sequence)
    for i in range(length_seq - D + 1):
        zeros = count_zeros(sequence[i:i + D])
        ones = count_ones(sequence[:i] + sequence[i + D:])
        sum_change = zeros + ones
        if sum_change < max_change:
            max_change = sum_change
    wy.write(str(max_change) + "\n")


for case in we:
    data = case.split()
    opt_dist(data[0], int(data[1]))

we.close()
wy.close()
