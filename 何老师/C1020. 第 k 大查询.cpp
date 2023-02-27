#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int maxn=500005;
int n,k;
int a[maxn],p[maxn],l[maxn],r[maxn];
bool cmp(int x,int y){
    return a[x]<a[y];
}
signed main()
{
    n=read();
    k=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
        p[i]=i;
    }
    for(int i=1;i<=n;++i){
        l[i]=i-1;
        r[i]=i+1;
    }
    sort(p+1,p+n+1,cmp);
    int id,li,lcnt,ri,rcnt,ls,rs,ans=0;
    for(int i=1;i<=n;++i){
        id=p[i];
        lcnt=1;
        for(li=id;l[li]&&lcnt<k;li=l[li],lcnt++);
        ri=id;rcnt=0;
        while(lcnt+rcnt<k&&r[ri]<=n){
            ri=r[ri];
            rcnt++;
        }
        if(lcnt+rcnt==k){
            while(ri<=n){
                ls=li-l[li];
                rs=r[ri]-ri;
                ans+=ls*rs*a[id];
                if(li==id) break;
                li=r[li];
                ri=r[ri];
            }
        }
        li=l[id];
        ri=r[id];
        r[li]=ri;
        l[ri]=li;
    }
    write(ans);
    putchar('\n');
    return 0;
}