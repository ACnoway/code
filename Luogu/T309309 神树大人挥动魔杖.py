n, k = input().split()
n = int(n)
k = int(k)
all = 9 * 10**(n - 1)
cnt = all // k
shao = all % k
for x in range(0, shao):
    print((cnt + 1) % 100000007, end=' ')
for x in range(shao, k):
    print(cnt % 100000007, end=' ')
# 100 101 102 103 104 105 106 107 108 109 110 900
