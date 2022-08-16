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
int n,ans,st,en;
int a[1003];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    st=a[1];
    for(int i=1;i<=n;++i){
        if(a[i]>a[i-1]){
            en=a[i];
        }
        else{
            ans=max(ans,en-st);
            st=a[i];
            en=a[i];
        }
    }
    ans=max(ans,en-st);
    cout<<ans<<endl;
    return 0;
}