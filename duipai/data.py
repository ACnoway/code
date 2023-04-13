import random
import os

n = 100
cnt = 0
while True:
    cnt += 1
    print("第 %d 组数据" % cnt)
    f = open('.\\duipai\\in.txt', 'w', encoding='utf-8')
    f.write(str(n) + ' ' + str(n) + '\n')
    for o in range(0, n):
        l = random.randint(1, n)
        r = random.randint(1, n)
        if l > r:
            l, r = r, l
        d = random.randint(0, 100000000)
        s = random.randint(0, 10000000)
        e = s + (r - l) * d
        f.write(str(l) + ' ' + str(r) + ' ' + str(s) + ' ' + str(e) + '\n')
    f.close()
    os.system(".\\duipai\\bl.exe < .\\duipai\\in.txt" + " > .\\duipai\\bl.txt")
    os.system(".\\duipai\\std.exe < .\\duipai\\in.txt" +
              " > .\\duipai\\std.txt")
    ret = os.system("fc .\\duipai\\bl.txt .\\duipai\\std.txt")
    ret >>= 8
    if ret == 1:
        break
