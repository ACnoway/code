#include<iostream>
#define int unsigned long long
using namespace std;
int a[130][130];
int d,n;
signed main()
{
    cin>>d>>n;
    int x,y,k;
    for(int i=1;i<=n;++i){
        cin>>x>>y>>k;
        a[x][y]+=k;
    }
    for(int i=1;i<=129;++i){
        for(int j=1;j<=129;++j) a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    }
    return 0;
}