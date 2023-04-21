from math import sqrt

_in = open("fib.in", "r", encoding="utf-8")
a = _in.readline().split()
_in.close()
b = [int(a[0]), int(a[1]), 0]
m = int(a[2])
n = int(a[3])
for x in range(1, n):
    b[2] = b[1] + b[0] + 2 * sqrt(3 + b[0] * b[1])
_out = open("fib.out", "w", encoding="utf-8")
_out.write(str(b[2]) + '\n')
