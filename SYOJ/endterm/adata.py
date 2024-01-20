import random
n=100000
f=open("magic.in","w",encoding="utf-8")
f.write(str(n)+'\n')
for x in range(0,n):
    f.write(str(random.randint(100000000,1000000000))+'\n')

