#include<iostream>
using namespace std;
int f[1510][1510];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j) cin>>f[i][j];
    }
    for(int i=n;i>=1;--i){
        for(int j=i;j>=1;--j)
            f[i][j]=max(f[i+1][j],f[i+1][j+1])+f[i][j];
    }
    cout<<f[1][1]<<endl;
    return 0;
}