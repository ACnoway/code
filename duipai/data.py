import random
import os

n = 100
cnt = 0
while True:
    cnt += 1
    print("第 %d 组数据" % cnt)

    # 数据部分
    f = open('.\\duipai\\in.txt', 'w', encoding='utf-8')

    f.write(str(n) + '\n')
    for o in range(0, n):
        l = random.randint(99999999999999999, 1000000000000000000)
        f.write(str(l) + '\n')

    f.close()

    # 对拍部分
    os.system(".\\duipai\\bl.exe < .\\duipai\\in.txt" + " > .\\duipai\\bl.txt")
    os.system(".\\duipai\\std.exe < .\\duipai\\in.txt" +
              " > .\\duipai\\std.txt")
    ret = os.system("fc .\\duipai\\bl.txt .\\duipai\\std.txt")
    print(ret)
    if ret == 1:
        break
