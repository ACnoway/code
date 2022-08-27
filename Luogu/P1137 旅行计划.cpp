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
const int N=200005;
int h[N],e[N],ne[N],idx;
int in[N],q[N];
int f[N];
int n,m,x,y;
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
    in[b]++;
}
int main()
{
    for(int i=0;i<N;++i) h[i]=-1;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>x>>y;
        add(x,y);
    }
    int hh=0,tt=-1;
    for(int i=1;i<=n;++i){
        if(!in[i]){
            f[i]=1;
            q[++tt]=i;
        }
    }
    while(hh<=tt){
        x=q[hh++];
        for(int i=h[x];i!=-1;i=ne[i]){
            y=e[i];
            f[y]=max(f[y],f[x]+1);
            if(--in[y]==0) q[++tt]=y;
        }
    }
    for(int i=1;i<=n;++i) cout<<f[i]<<endl;
    return 0;
}