#include <iostream>
using namespace std;
int n;
int a[120][120];
int main()
{
    cin>>n;
    for(int i=2;i<=n;++i) a[i][0]=10000,a[0][i]=10000;
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) cin>>a[i][j],a[i][j]+=min(a[i-1][j],a[i][j-1]);
    /*for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) cout<<a[i][j]<<' ';
        cout<<endl;
    }*/
    cout<<a[n][n]<<endl;
    return 0;
}