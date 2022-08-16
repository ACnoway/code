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
int a[102];
int n,m;
int main()
{
    cin>>n>>m;
    int ans=0;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            for(int k=j+1;k<n;++k){
                if(a[i]+a[j]+a[k]<=m) ans=max(ans,a[i]+a[j]+a[k]);
            }
        }
    }
    cout<<ans;
    return 0;
}