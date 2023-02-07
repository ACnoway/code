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
long long t,l,r,cnt,ans;
int main()
{
    cin>>t;
    while(t--){
        cin>>l>>r;
        cnt=(r-l+1)%9;
        ans=cnt*(l%9)%9+cnt*(cnt-1)%9*5%9;
        cout<<ans%9<<endl;
    }
    return 0;
}