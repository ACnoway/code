#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<climits>
#define ll long long
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
int n;
int ps[30]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
ll ans=LONG_LONG_MAX;
void dfs(ll now,int k,int ls,int cnt){
    if(now<=0ll||now>ans) return;
    if(cnt>n) return;
    if(k>16) return;
    if(cnt==n){
        ans=now;
        return;
    }
    for(int i=1;i<=ls;++i){
        dfs(now*=ps[k],k+1,i,cnt*(i+1));
    }
}
int main()
{
    n=read();
    dfs(1ll,1,64,1);
    printf("%lld\n",ans);
    return 0;
}