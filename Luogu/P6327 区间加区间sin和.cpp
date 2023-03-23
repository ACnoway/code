#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl
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
const int N=200005;
int n,m;
int a[N];
struct Segnode{
    int l,r,sum,lt;
}segt[N<<2];
int main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    m=read();
    int op,l,r,v;
    while(m--){
        op=read();
        l=read(); r=read();
        if(op==1){
            v=read();
            add(1,l,r,v);
        }
        else{
            printf("%.1lf",query(1,l,r));
        }
    }
    return 0;
}