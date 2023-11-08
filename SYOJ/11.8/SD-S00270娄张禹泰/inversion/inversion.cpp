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
const int N=500005;
int n;
int a[N],bit[N];
inline int lb(int x){return x&-x;}
inline void add(int x){
    while(x<=n) ++bit[x],x+=lb(x);
}
inline int que(int x){
    int res=0;
    while(x) res+=bit[x],x-=lb(x);
    return res;
}
int main()
{
    freopen("inversion.in","r",stdin);
    freopen("inversion.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    int cnt=0,tmp=0;
    for(int i=n;i;--i){
        add(a[i]+1);
        cnt+=que(a[i]);
    }
    while(next_permutation(a+1,a+n+1)){
        for(int i=0;i<=n;++i) bit[i]=0;
        tmp=0;
        for(int i=n;i;--i){
            add(a[i]+1);
            tmp+=que(a[i]);
        }
        if(tmp==cnt){
            for(int i=1;i<=n;++i) printf("%d ",a[i]);
            printf("\n");
            return 0;
        }
    }
    return 0;
}