import random
import sys

T = 100000
f = open('.\\Luogu\\126873\\Bdata.txt','w',encoding='utf-8')
f.write(str(T)+'\n')
for x in range(0,T):
    f.write(str(random.randint(10,5000000))+'\n')
f.close()