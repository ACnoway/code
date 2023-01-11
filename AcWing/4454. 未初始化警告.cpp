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
int n,k,x,y,ans;
bool v[100005];
int main()
{
    cin>>n>>k;
    v[0]=1;
    for(int i=1;i<=k;++i){
        cin>>x>>y;
        ans+=(!v[y]);
        v[x]=1;
    }
    cout<<ans<<endl;
    return 0;
}