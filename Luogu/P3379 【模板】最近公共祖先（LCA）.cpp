#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
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
const int N=500005;
int n,m,s,cnt;
int id[N];
struct node{
    int v,p;
    bool operator <(const node b)const{
        return v<b.v;
    }
}st[22][N<<2];
vector<int> e[N];
void dfs(int x,int fa,int dep){
    id[x]=++cnt;
    st[0][cnt]={dep,x};
    int v;
    for(auto i:e[x]){
        if(i!=fa){
            dfs(i,x,dep+1);
            st[0][++cnt]={dep,x};
        }
    }
}
inline int query(int l,int r){
    int k=__lg(r-l+1);
    return min(st[k][l],st[k][r-(1<<k)+1]).p;
}
int main()
{
    n=read();
    m=read();
    s=read();
    int u,v;
    for(int i=1;i<n;++i){
        u=read();
        v=read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(s,0,1);
    for(int i=1;i<22;++i){
        for(int j=1;j+(1<<i)-1<=cnt;++j){
            st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
    int x,y;
    for(int i=1;i<=m;++i){
        x=read();
        y=read();
        printf("%d\n",query(min(id[x],id[y]),max(id[x],id[y])));
    }
    return 0;
}