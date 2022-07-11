#include <iostream>
using namespace std;
int t,r,c;
int a[120][120];
int main()
{
    cin>>t;
    while(t--){
        cin>>r>>c;
        for(int i=1;i<=r;++i){
            for(int j=1;j<=c;++j) cin>>a[i][j],a[i][j]+=max(a[i-1][j],a[i][j-1]);
        }
        cout<<a[r][c]<<endl;
    }
    return 0;
}