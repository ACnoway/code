#include<iostream>
#include<cstdio>
using namespace std;
int f[51][51][51][51],a[51][51];
signed main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=n;k++){
                for(int l=1;l<=m;l++){
                    f[i][j][k][l]=max(f[i-1][j][k-1][l],max(f[i][j-1][k][l-1],max(f[i-1][j][k][l-1],f[i][j-1][k-1][l])))+a[i][j]+a[k][l];
                    if(i==k&&l==j) f[i][j][k][l]-=a[i][j];
                }
            }
        }
    }
    cout<<f[n][m][n][m]<<endl;
    return 0;
}