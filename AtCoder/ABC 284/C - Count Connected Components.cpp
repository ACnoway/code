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
int n,m,u,v,ans;
int f[102];
int find(int x){
    if(f[x]!=x) f[x]=find(f[x]);
    return f[x];
}
void merge(int x,int y){
    f[find(x)]=find(y);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i) f[i]=i;
    for(int i=1;i<=m;++i){
        cin>>u>>v;
        merge(u,v);
    }
    for(int i=1;i<=n;++i) ans+=(find(i)==i);
    cout<<ans<<endl;
    return 0;
}