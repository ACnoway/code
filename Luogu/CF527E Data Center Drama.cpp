#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#define int long long
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
const int N=200005,M=1000006;
int n,m,cnt;
int du[N];
bool vis[M];
vector<int> ji;
struct node{
    int to,nxt;
}e[M];
int idx=1,head[N];
inline void add(int u,int v){
    e[++idx].to=v;
    e[idx].nxt=head[u];
    head[u]=idx;
}
void dfs(int x){
    //因为要删边所以i要加取地址符更改head[x]
    for(int &i=head[x];i;i=e[i].nxt){
        if(vis[i]) continue;
        //debug(x);
        //debug(head[x]);
        vis[i]=vis[i^1]=1;
        int y=e[i].to;
        dfs(y);
        //debug(cnt);
        if((++cnt)&1) printf("%d %d\n",x,y);
        else printf("%d %d\n",y,x);
    }
}
signed main()
{
    n=read(); m=read();
    int x,y;
    for(int i=1;i<=m;++i){
        x=read(); y=read();
        ++du[x]; ++du[y];
        add(x,y); add(y,x);
    }
    for(int i=1;i<=n;++i){
        if(du[i]&1) ji.push_back(i);
    }
    for(int i=0;i+1<ji.size();i+=2){
        ++du[ji[i]]; ++du[ji[i+1]];
        add(ji[i],ji[i+1]);
        add(ji[i+1],ji[i]);
        ++m;
    }
    if(m&1){
        du[1]+=2;
        add(1,1);
        add(1,1);
        ++m;
    }
    printf("%d\n",m);
    dfs(1);
    return 0;
}