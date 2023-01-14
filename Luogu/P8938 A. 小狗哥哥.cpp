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
double m;
int l,r=1000000009;
int n;
double a[100005];
bool flag;
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        l=max(l,(int)ceil(m/a[i]/(double)i));
        debug(a[i]);
        if(a[i]-1) r=min(r,(int)ceil(m/(a[i]-1)/(double)i)),flag=1;
    }
    debug(r);
    if(l-1>r) cout<<0<<endl;
    else if(flag) cout<<r-l<<endl;
    else cout<<"xiaogougege"<<endl;
    return 0;
}