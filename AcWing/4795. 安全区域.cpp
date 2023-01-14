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
int n,m,x,y,cx,cy,ans;
bool vx[100005],vy[100005];
int main()
{
    cin>>n>>m;
    ans=n*n;
    for(int i=1;i<=m;++i){
        cin>>x>>y;
        ans=ans-n-n;
        if(!vx[x]&&!vy[y]){
            vx[x]=1;vy[y]=1;
            ans+=cx+cy;
            cx++;cy++;
        }
        else{
            ans+=n;
        }
        cout<<ans<<endl;
    }
    return 0;
}