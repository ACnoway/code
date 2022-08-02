#include<iostream>
#include<cstring>
using namespace std;
const int N=10004;
int n,m,x,y,z;
int f[N][N],d[N],a[N];
bool v[N];
bool dij(int x){
    memset(d,127,sizeof d);
    memset(v,0,sizeof v);
    d[x]=0;
    v[x]=1;
    for(int i=1;i<=n;++i){
        int t=a[i];
        v[t]=1;
        for(int j=1;j<=n;++j){
            if(!v[j]&&d[j]<d[t]) return 0;
        }
        for(int j=1;j<=n;++j){
            d[j]=min(d[j],d[t]+f[t][j]);
        }
    }
    return 1;
}
int main()
{
    cin>>n>>m;
    memset(f,127,sizeof f);
    while(m--){
        cin>>x>>y>>z;
        f[x][y]=f[y][x]=z;
    }
    cin>>m;
    while(m--){
        for(int i=1;i<=n;++i) cin>>a[i];
        if(dij(a[1])) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}