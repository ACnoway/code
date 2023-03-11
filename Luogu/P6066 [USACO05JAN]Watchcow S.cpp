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
const int N=10004,M=100005;
typedef pair<int,int> pii;
int n,m,cnt;
int top,tp,ans[M],st[M],nxt[N];
bool vis[M];
vector<pii> e[N];
void dfs(){
    st[++tp]=1;
    while(tp){
        int x=st[tp],i=nxt[x];
        while(i<e[x].size()&&vis[e[x][i].second]) i++;
        if(i<e[x].size()){
            st[++tp]=e[x][i].first;
            vis[e[x][i].second]=1;
            nxt[x]=i+1;
        }
        else{
            tp--;
            ans[++top]=x;
        }
    }
}
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=m;++i){
        int u=read(),v=read();
        ++cnt;
        e[u].push_back({v,cnt});
        ++cnt;
        e[v].push_back({u,cnt});
    }
    dfs();
    for(int i=1;i<=top;++i) printf("%d\n",ans[i]);
    return 0;
}