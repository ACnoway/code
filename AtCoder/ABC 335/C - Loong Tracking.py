n,q=map(int,input().split())
p=[(i,0) for i in range(n,0,-1)]
x,y=1,0
for _ in range(q):
    t,c=input().split()
    if t=='1':
        if c=='R':
            x+=1
        elif c=='L':
            x-=1
        elif c=='U':
            y+=1
        elif c=='D':
            y-=1
        p.append((x,y))
    else:
        print(*p[-int(c)])
