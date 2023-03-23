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
const int N=2000006;
int n;
vector<pair<int,int> > e[N];
int sum[N];
void dfs(int x,int die){
    for(auto to:e[x]){
        int v=to.first,w=to.second;
        if(v!=die){
            sum[v]=sum[x]^w;
            dfs(v,x);
        }
    }
}
struct Trie{
    int ch[2];
}trie[N];
int cnt;
void build(int w,int x){
    for(int i=(1<<30);i;i>>=1){
        bool d=w&i;
        if(!trie[x].ch[d]) trie[x].ch[d]=++cnt;
        x=trie[x].ch[d];
    }
}
int query(int w,int x){
    int ans=0;
    for(int i=(1<<30);i;i>>=1){
        bool d=w&i;
        if(trie[x].ch[!d]){
            ans+=i;
            x=trie[x].ch[!d];
        }
        else x=trie[x].ch[d];
    }
    return ans;
}
int main()
{
    n=read();
    int u,v,w;
    for(int i=1;i<n;++i){
        u=read();
        v=read();
        w=read();
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    dfs(1,0);
    for(int i=1;i<=n;++i) build(sum[i],0);
    int ans=0;
    for(int i=1;i<=n;++i) ans=max(ans,query(sum[i],0));
    printf("%d\n",ans);
    return 0;
}