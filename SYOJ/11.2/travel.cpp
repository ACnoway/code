#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl
#endif
using namespace std;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x*f;
}
const int N=100005,M=200005;
int n,m;
typedef pair<int,int> pii;
pii a[N];
int idx,head[N],to[M],nxt[M];
bool cmp(pii a,pii b){
    return a.first>b.first;
}
int q[N],h,t;
bool vis[N];
void bfs(int x){
    h=t=0;
    for(int i=0;i<N;++i) vis[i]=0;
    q[++t]=x;
    vis[x]=1;
    
}
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;++i) a[i].first=read(),a[i].second=i;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;++i){
        bfs(a[i].second);
    }
    return 0;
}