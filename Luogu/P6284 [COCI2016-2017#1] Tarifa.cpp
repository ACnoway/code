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
int x,n,ans;
int main()
{
    cin>>x>>n;
    int tmp;
    for(int i=1;i<=n;++i){
        cin>>tmp;
        ans+=x-tmp;
    }
    cout<<ans+x<<endl;
    return 0;
}