#include <iostream>
#include <cstring>
using namespace std;
int n,m,ans=0,op,nn,mm;
int f[20][20];
char a[1003][20],b[20];
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i) cin>>a[i]+1;
    while(m--){
        ans=0;
        cin>>b+1>>op;
        mm=strlen(b+1);
        for(int t=0;t<n;++t){
            nn=strlen(a[t]+1);
            for(int i=1;i<=nn;++i) f[i][0]=i;
            for(int i=1;i<=mm;++i) f[0][i]=i;
            for(int i=1;i<=nn;++i){
                for(int j=1;j<=mm;++j){
                    f[i][j]=min(f[i-1][j],f[i][j-1])+1;
                    f[i][j]=min(f[i][j],f[i-1][j-1]+(a[t][i]!=b[j]));
                }
            }
            if(f[nn][mm]<=op) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}