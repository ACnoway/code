from itertools import permutations
import time
import os
a=[1,2,3,4,5,6,7,8,9,10,11]
n=11
qs=[]
s=[1,11,55,165,330,462,462,330,165,55,11,1]
for res in permutations(a,len(a)):
    tmp=0
    for x in range(0,n):
        tmp+=res[x]*s[x]
    if tmp<=12345:
        f=open("p.in","w",encoding='utf-8')
        f.write(f"{str(n)} {str(tmp)}\n")
        f.close()
        st=time.process_time()
        os.system('.\\A.exe')
        tcost=time.process_time()-st
        f=open("p.out",'r',encoding='utf-8')
        ans=f.readline().split(' ')
        at=0
        for x in range(0,n):
            at+=int(ans[x])*s[x]
        if at!=tmp:
            print(f"答案有误，期待总和{str(tmp)}，获得总和{str(at)}")
        if tcost>1:
            print(f"耗时{str(tcost)}秒")
print(qs)