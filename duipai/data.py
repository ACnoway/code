import random
import os
import time
import datetime

n = 100000
k = 100000
Times = 200000
cnt = 0
lst=0
while True:
    cnt += 1
    print("第 %d 组数据" % cnt)

    # 数据部分
    f = open('.\\duipai\\in.txt', 'w', encoding='utf-8')

    # f.write(str(n)+'\n')
    # for x in range(0,n):
    #     f.write(str(random.randint(0,1000000000))+' ')
    #     # f.write('0 ')
    # f.write('\n'+str(k)+'\n')
    # for x in range(0,k):
    #     f.write(str(random.randint(0,1000000000))+'\n')
    #     # f.write('1000000000\n')

    f.write(str(Times)+'\n')
    for x in range(0,Times):
        f.write(str(random.randint(10,5000000))+'\n')

    f.close()

    # 对拍部分
    # os.system(".\\duipai\\bl.exe < .\\duipai\\in.txt" + " > .\\duipai\\bl.txt")
    # st = time.process_time()
    os.system("\".\\duipai\\std.exe\" < .\\duipai\\in.txt" +
              " > .\\duipai\\std.txt")
    en = time.process_time()
    # ret = os.system("fc .\\duipai\\bl.txt .\\duipai\\std.txt")
    # print(ret)
    # st = datetime.datetime.fromtimestamp(st)
    # en = datetime.datetime.fromtimestamp(en)
    # cha = en - st
    print("std用时："+str(en-lst))
    lst=en
    ret = en-lst > 1
    if ret == 1:
        break
