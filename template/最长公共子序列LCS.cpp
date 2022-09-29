#include<iostream>
#include<cstring>
using namespace std;
int n,m;
char a[1003],b[1003];
int f[1003][1003];
int main()
{
    cin>>a+1>>b+1;
    n=strlen(a+1);
    m=strlen(b+1);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if(a[i]==b[j]) f[i][j]=max(f[i][j],f[i-1][j-1]+1);
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}