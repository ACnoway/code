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
const int N=50004;
int n,m;
int a[N],bl[N],g[N][2];
struct wenti{
    int l,r,id,d;
    bool operator <(const wenti &x)const{
        return (bl[l]^bl[x.l])?bl[l]<bl[x.l]:(bl[l]&1)?r<x.r:r>x.r;
    }
}q[N<<2];
int main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    m=read();
    for(int i=1;i<=m;++i){
        a[]
    }
    return 0;
}