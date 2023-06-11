pi = 3.1415926535898
e = 2.7182818284590


def factorial(n):
    val = 1
    for i in range(1, n + 1):
        val *= i
    return val


def double_factorial(n):
    val = 1
    for i in range(n, 1, -2):
        val *= i
    return val


def gamma(double_value):
    val = double_value // 2
    if double_value % 2 == 0:
        return factorial(val - 1)
    else:
        return (double_factorial(double_value - 2) / 2 ** val) * pi ** (1 / 2)


def f(n, x):
    a = 1 / (2 ** (n / 2) * gamma(n))
    b = x ** (n / 2 - 1)
    c = 1 / (e ** (x / 2))
    return a * b * c


def approximate_difinite_integral(lower_bound, upper_bound, n, divisions):
    h = (upper_bound - lower_bound) / (2 * divisions)
    step = (upper_bound - lower_bound) / divisions

    sum = 0
    for i in range(1, divisions):
        sum += f(n, lower_bound + i * step) * 2

    sum += f(n, lower_bound)
    sum += f(n, upper_bound)

    return h * sum


lower_bound = 0

n = 3
print("\nCalculate approximated definite integral with n = " + str(n) + "\n")
for upper_bound in range(1, 51, 1):
    print(approximate_difinite_integral(lower_bound, upper_bound, n, 10000))

n = 5
print("\nCalculate approximated definite integral with n = " + str(n) + "\n")
for upper_bound in range(1, 51, 1):
    print(approximate_difinite_integral(lower_bound, upper_bound, n, 10000))

n = 10
print("\nCalculate approximated definite integral with n = " + str(n) + "\n")
for upper_bound in range(1, 51, 1):
    print(approximate_difinite_integral(lower_bound, upper_bound, n, 10000))

n = 20
print("\nCalculate approximated definite integral with n = " + str(n) + "\n")
for upper_bound in range(1, 51, 1):
    print(approximate_difinite_integral(lower_bound, upper_bound, n, 10000))

n = 30
print("\nCalculate approximated definite integral with n = " + str(n) + "\n")
for upper_bound in range(1, 51, 1):
    print(approximate_difinite_integral(lower_bound, upper_bound, n, 10000))

