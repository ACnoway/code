#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int n,m;
bool ans=0;
char a[1003][1003],b[1003][1003],c[4][4];
int dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={0,-1,1,-1,1,0,-1,1};
bool ck(){
    bool tmp=1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i][j]!=b[i][j]){
                tmp=0;
                if(a[i][j]=='.'&&b[i][j]=='#') return 0;
            }
        }
    }
    ans=(ans||tmp);
    return 1;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i]+1;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) b[i][j]='.';
    dfs(2,2);
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}