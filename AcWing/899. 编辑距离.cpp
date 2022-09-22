#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int f[20][20];
char a[1003][20];
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i) cin>>a[i]+1;
    int ans=0,op;
    while(m--){
        char b[20];
        cin>>b+1>>op;
        ans=0;
        for(int t=0;t<n;++t){
            for(int i=1;i<=strlen(a[t]);++i) f[i][0]=i;
            for(int i=1;i<=strlen(b);++i) f[0][i]=i;
            for(int i=1;i<=strlen(a[t]);++i){
                for(int j=1;j<=strlen(b);++j) f[i][j]=0;
            }
            for(int i=1;i<=strlen(a[t]);++i){
                for(int j=1;j<=strlen(b);++j){
                    f[i][j]=min(f[i-1][j],f[i][j-1])+1;
                    if(a[t][i-1]==b[j-1]) f[i][j]=min(f[i][j],f[i-1][j-1]);
                    else f[i][j]=min(f[i][j],f[i-1][j-1]+1);
                }
            }
            cout<<f[strlen(a[t])][strlen(b)]<<endl;
            if(f[strlen(a[t])][strlen(b)]<=op) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}