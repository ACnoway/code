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
int t,n,ma1,ma2,mi1,mi2;
int a[100005];
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;++i) cin>>a[i];
        sort(a,a+n);
        cout<<a[n-1]+a[n-2]-a[0]-a[1]<<endl;
    }
    return 0;
}