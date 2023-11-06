import random
import time
import datetime
from os import system

cnt = 0
q = 500000
while True:
    cnt += 1
    print(f"第 {str(cnt)} 组数据")
    # f = open(".\\cake\\output\\cake.in", "w", encoding="utf-8")
    # f.write(str(q) + '\n')
    # for x in range(0, q):
    #     f.write(str(random.randint(1, 5000000)) + '\n')
    # f.close()
    st = time.time()
    bl = system(
        ".\\cake\\output\\bl.exe < .\\cake\\output\\cake.in > .\\cake\\output\\cake.ans"
    )
    en = time.time()
    st = datetime.datetime.fromtimestamp(st)
    en = datetime.datetime.fromtimestamp(en)
    cha = en - st
    print("bl用时：" + str(cha.total_seconds()))
    print(bl)
    st = time.time()
    std = system(
        ".\\cake\\output\\cake.exe < .\\cake\\output\\cake.in > .\\cake\\output\\cake.out"
    )
    en = time.time()
    st = datetime.datetime.fromtimestamp(st)
    en = datetime.datetime.fromtimestamp(en)
    cha = en - st
    print("std用时：" + str(cha.total_seconds()))
    print(std)
    ret = system("fc .\\cake\\output\\cake.ans .\\cake\\output\\cake.out")
    print(ret)
    if cha.total_seconds() > 1 or ret == 1:
        print("std用时：" + str(cha.total_seconds()))
        break
