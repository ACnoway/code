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
int k,n;
int a[30];
int f[30][30];
int main()
{
    cin>>k>>n;
    for(int i=0;i<k;++i){
        for(int j=0;j<n;++j) cin>>a[j];
        for(int j=0;j<n;++j){
            debug(a[j]);
            for(int o=j+1;o<n;++o) f[a[j]][a[o]]++;
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(f[i][j]==k) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}