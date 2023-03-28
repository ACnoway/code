import random

n = 500000
a = []
for x in range(1, n + 1):
    a.append(x)
random.shuffle(a)
f = open(".\\NFLSOJ\\ltc.in", "+w", encoding="utf-8")
f.write("2\n")
f.write(str(n) + '\n')
for x in range(1, n):
    f.write("1 " + str(x + 1) + '\n')
for x in range(0, n):
    f.write(str(a[x]) + ' ')
f.write('\n')
f.write(str(n) + '\n')
for x in range(1, n):
    f.write(str(x) + ' ' + str(x + 1) + '\n')
random.shuffle(a)
for x in range(0, n):
    f.write(str(a[x]) + ' ')
f.write('\n')
