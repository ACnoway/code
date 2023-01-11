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
int t,n,a,ans;
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;++i){
            cin>>a;
            ans+=a&1;
        }
        cout<<ans<<endl;
    }
    return 0;
}