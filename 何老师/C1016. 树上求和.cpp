#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
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
const int maxn=100005;
int n,rt,x,y;
int rd[maxn],nid[maxn],c[maxn],fa[maxn];
int e,h[maxn],ne[maxn],to[maxn];
inline void add(int u,int v){
    to[++e]=v;
    ne[e]=h[u];
    h[u]=e;
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i) c[i]=read();
    for(int i=1;i<n;++i){
        x=read();
        y=read();
        add(x,y);
    }
    return 0;
}