#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int n,m,k;
int t[3003][3003];
char a[3003][3003];
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i) cin>>a[i]+1;
    long long ans=1,cnt=0;
    for(int i=1;i<=n;++i){
        cnt=0;
        for(int j=1;j<=m;++j){
            if(a[i][j]!=a[i][j-1]) cnt++;
        }
        ans*=cnt;
        cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
