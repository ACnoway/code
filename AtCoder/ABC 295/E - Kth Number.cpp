#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
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
const int N=2003;
int n,m,k,lcnt;
int a[N];
signed main()
{
    n=read(); m=read();
    k=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
        lcnt+=(!a[i]);
    }
    int ans=0,st=1,cnt,xiao,deng;
    sort(a+1,a+1+n);
    for(;a[st]==0;++st);
    for(int i=1;i<=m;++i){
        cnt=0;
        for(int j=st;j<=n;++j){
            if(a[j]<i) xiao++;
            else if(a[j]==i) deng++;
            else break;
        }
        if(xiao+deng<k){
            continue;
        }
        
    }
    return 0;
}