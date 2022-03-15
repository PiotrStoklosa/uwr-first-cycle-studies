from sortedcontainers import SortedList

text = open("pan_tadeusz_bez_spacji.txt", encoding="utf8")
words = open("words_for_ai1.txt", encoding="utf8")

inputFile = open("zad2_input.txt", encoding="utf8")
outputFile = open("zad2_output.txt", "w", encoding="utf8")

w = words.read().splitlines()[1:]
s = SortedList(w)


def divide_text(line):
    line = line.strip()
    dynamic_solution = [(0, None)] * (len(line) + 1)
    for i in range(len(line) + 1):
        if line[:i] in s:
            dynamic_solution[i] = (i ** 2, line[:i])
        else:
            for j in range(i + 1):
                if dynamic_solution[j][0] != 0 and line[j:i] in s:
                    if dynamic_solution[j][0] + (i - j) ** 2 > dynamic_solution[i][0]:
                        dynamic_solution[i] = (
                            dynamic_solution[j][0] + (i - j) ** 2, dynamic_solution[j][1] + " " + line[j:i])
    outputFile.write(dynamic_solution[len(line)][1] + "\n")


for i in text:
    divide_text(i)

inputFile.close()
outputFile.close()
text.close()
words.close()
