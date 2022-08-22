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
int t,n,ans;
int a[200005];
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i) cin>>a[i];
        ans=0;
        for(int i=2;i<n;++i){
            if(a[i]>a[i-1]&&a[i]>a[i+1]){
                a[i+1]=max(a[i],a[i+2]);
                ans++;
            }
        }
        cout<<ans<<endl;
        for(int i=1;i<=n;++i) cout<<a[i]<<' ';
        cout<<endl;
    }
    return 0;
}