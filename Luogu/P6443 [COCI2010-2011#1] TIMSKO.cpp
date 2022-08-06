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
int n,m,k;
int main()
{
    cin>>m>>n>>k;
    int ans=0;
    for(int i=1;i<=n;++i){
        int mm=m-i*2,nn=n-i;
        debug(mm);
        debug(nn);
        if(mm+nn>=k&&mm>=0&&nn>=0) ans=i;
        debug(ans);
    }
    cout<<ans<<endl;
    return 0;
}