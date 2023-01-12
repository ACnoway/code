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
int n,m,l,r,a1,a2;
int a[100005],b[100005],c[100005];
signed main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;++i){
        cin>>l>>r;
        b[l]++;
        b[r+1]--;
    }
    for(int i=1;i<=n;++i) b[i]+=b[i-1];
    for(int i=1;i<=n;++i) a1+=a[i]*b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for(int i=1;i<=n;++i) a2+=a[i]*b[i];
    cout<<a2-a1<<endl;
    return 0;
}