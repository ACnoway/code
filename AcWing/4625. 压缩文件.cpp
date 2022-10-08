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
struct node{
    int a,b,c;
}a[100005];
int n,m;
bool cmp(node a,node b){
    return a.c>b.c;
}
signed main()
{
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;++i) cin>>a[i].a>>a[i].b,a[i].c=a[i].a-a[i].b,cnt+=a[i].a;
    sort(a+1,a+1+n,cmp);
    int ans=0;
    for(int i=1;i<=n;++i){
        if(cnt<=m) break;
        cnt-=a[i].c;
        ans++;
    }
    if(cnt>m) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}