#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,k;
int a[1003][1003],f[1003][1003];
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j) cin>>a[i][j],f[a[i][j]][j]=1;
    }
    int ans=0;
    for(int i=1;i<=k;++i){
        ans=0;
        for(int j=1;j<=m;++j) ans+=f[i][j];
        cout<<ans<<' ';
    }
    return 0;
}