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
int a[1503][1503];
int n,m,x,y,z;
int main()
{
    cin>>n>>m;
    for(int i=0;i<=n;++i){
        for(int j=0;j<=n;++j){
            if(i==j) a[i][j]=0;
            else a[i][j]=1e9;
        }
    }
    for(int i=0;i<m;++i){
        cin>>x>>y>>z;
        a[x][y]=min(a[x][y],-z);
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(a[i][k]!=1e9&&a[k][j]!=1e9){
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
                }
            }
        }
    }
    if(a[1][n]==1e9) cout<<"-1";
    else cout<<a[1][n]*-1;
    return 0;
}