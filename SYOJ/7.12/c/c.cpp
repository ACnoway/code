#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int n,ans;
struct node{
    int v,p,pre,nxt;
    bool operator <(const node &x)const{
        return v<x.v;
    }
}a[600];
int pv[600];
signed main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    cin>>n;
    a[0].v=a[n+1].v=1;
    for(int i=1;i<=n;++i){
        cin>>a[i].v;
        a[i].p=i;
        a[i].pre=i-1;
        a[i].nxt=i+1;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i) pv[a[i].p]=i;
    for(int i=1;i<=n;++i){
        ans+=a[i].v*a[pv[a[i].pre]].v*a[pv[a[i].nxt]].v;
        a[pv[a[i].pre]].nxt=a[i].nxt;
        a[pv[a[i].nxt]].pre=a[i].pre;
    }
    cout<<ans<<endl;
    return 0;
}