import random
import time
import datetime
from os import system

cnt = 0
q = 500000
while True:
    cnt += 1
    print(f"第 {str(cnt)} 组数据")
    f = open(".\\guess\\output\\guess.in", "w", encoding="utf-8")
    f.write(str(q) + '\n')
    for x in range(0, q):
        f.write(str(random.randint(1, 5000000)) + '\n')
    f.close()
    st = time.time()
    bl = system(
        ".\\guess\\output\\bl.exe < .\\guess\\output\\guess.in > .\\guess\\output\\guess.ans"
    )
    en = time.time()
    st = datetime.datetime.fromtimestamp(st)
    en = datetime.datetime.fromtimestamp(en)
    cha = en - st
    print("bl用时：" + str(cha.total_seconds()))
    print(bl)
    st = time.time()
    std = system(
        ".\\guess\\output\\guess.exe < .\\guess\\output\\guess.in > .\\guess\\output\\guess.out"
    )
    en = time.time()
    st = datetime.datetime.fromtimestamp(st)
    en = datetime.datetime.fromtimestamp(en)
    cha = en - st
    print("std用时：" + str(cha.total_seconds()))
    print(std)
    ret = system("fc .\\guess\\output\\guess.ans .\\guess\\output\\guess.out")
    print(ret)
    if cha.total_seconds() > 1 or ret == 1:
        print("std用时：" + str(cha.total_seconds()))
        break
