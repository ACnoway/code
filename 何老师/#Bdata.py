import random

n = 1000000000000000
k = random.choice([random.randint(1, 10), random.randint(900, 1000)])
q = 100000
f = open(".\\何老师\\#B.in", "w", encoding="utf-8")
f.write(str(n) + ' ' + str(k) + ' ' + str(q) + '\n')
for t in range(0, q):
    x = random.randint(1, n)
    y = random.randint(1, n)
    while x == y:
        x = random.randint(1, n)
    f.write(str(x) + ' ' + str(y) + '\n')
