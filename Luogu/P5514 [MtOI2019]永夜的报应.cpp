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
int n,x,ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>x,ans^=x;
    cout<<ans<<endl;
    return 0;
}