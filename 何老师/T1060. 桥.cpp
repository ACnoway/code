#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<vector<pii> > e;
vector<vector<int> > g;
void dij(int s,vector<int> &vis,vector<int> &dis,vector<int> &pre){
    dis[s]=0;
    priority_queue<pii,vector<pii>,greater<pii> > q;
    q.push({dis[s],s});
    while(!q.empty()){
        auto p=q.top();
        q.pop();
        int u=p.second;
        if(vis[u]) continue;
        vis[u]=1;
        for(auto i:e[u]){
            int v=i.first,w=i.second;
            if(dis[v]==-1||dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                pre[v]=u;
                q.push({dis[v],v});
            }
        }
    }
}
vector<int> rt,tag;
void dfs(int x,int root){
    rt[x]=root;
    for(auto v:g[x]){
        if(tag[v]) continue;
        dfs(v,root);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    e.resize(n);
    g.resize(n);
    for(int i=0;i<m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        --u;--v;
        if(u==v) continue;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    vector<int> vis(n),dis(n-1),pre(n,-1),key;
    tag.resize(n);
    vector<int> vis2(n),dis2(n,-1),pre2(n,-1);
    dij(0,vis,dis,pre);
    int tmp=n-1;
    while(tmp){
        key.push_back(tmp);
        tag[tmp]=1;
        tmp=pre[tmp];
    }
    reverse(key.begin(),key.end());
    dij(n-1,vis2,dis2,pre2);
    for(int v=0;v<n;++v){
        if(pre[v]==-1) continue;
        int u=pre[v];
        e[u].erase(find(e[u].begin(),e[u].end(),(pii){v,dis[v]-dis[u]}));
        e[v].erase(find(e[v].begin(),e[v].end(),(pii){u,dis[v]-dis[u]}));
        g[u].push_back(v);
    }
    rt.assign(n,-1);
    for(auto i:key){
        dfs(i,i);
    }
    return 0;
}