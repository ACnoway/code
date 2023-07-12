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
int n,ma;
int a[300000];
int f[300005][71];
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        f[i][a[i]]=i;
        ma=max(ma,a[i]);
    }
    for(int j=1;j<=70;++j){
        for(int i=1;i<=n;++i){
            if(f[i][j-1]&&f[f[i][j-1]+1][j-1]){
                f[i][j]=f[f[i][j-1]+1][j-1];
                ma=max(ma,j);
            }
        }
    }
    cout<<ma<<endl;
    return 0;
}