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
const int mod=1e9+7;
int n,k,ans;
int a[20];
void dfs(int x,int c){
    for(int i=1;i<=k;++i){
        if(a[i]==0||i==c) continue;
        --a[i];
        dfs(x+1,i);
        ++a[i];
    }
    if(x==n){
        ++ans;
        ans%=mod;
    }
}
int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    cin>>k;
    for(int i=1;i<=k;++i) cin>>a[i],n+=a[i];
    for(int i=1;i<=k;++i){
        --a[i];
        dfs(1,i);
        ++a[i];
    }
    cout<<ans<<endl;
    return 0;
}