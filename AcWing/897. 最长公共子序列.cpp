#include<iostream>
using namespace std;
string a,b;
int f[1003][1003];
int n,m;
int main()
{
    cin>>n>>m;
    cin>>a>>b;
    int ans=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(a[i]==b[j]) f[i][j]=f[i-1][j-1]+1;
            else f[i][j]=max(f[i-1][j],f[i][j-1]);
            ans=max(ans,f[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}