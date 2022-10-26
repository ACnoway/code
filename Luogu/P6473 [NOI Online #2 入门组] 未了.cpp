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
int n,q,l,v;
int a[200005],b[200005];
bool cmp(int a,int b){
    return a>b;
}
signed main()
{
    cin>>n>>l>>v;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;++i) a[i]+=a[i-1];
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        t=t*v-l;
        if(t<0) cout<<0<<endl;
        else if(a[n]>t) cout<<upper_bound(a+1,a+n+1,t)-a<<endl;
        else cout<<-1<<endl;
    } 
    return 0;
}