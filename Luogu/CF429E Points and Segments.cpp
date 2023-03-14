/* 
  * 很妙的做法，通过差分把区间操作转化为点的操作
  * 这样给差分的点连边，就能把最后点权为0的判断转化成每个点的
  * 出度和入度相同的操作
*/
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
const int N=100005;
int n;
int l[N],r[N],du[N<<1],now[N<<1],color[N<<1];
bool vis[N<<1],nodevis[N<<1];
vector<int> a;
struct node{
    int v,id;
};
vector<node> e[N<<1];
void dfs(int x){
    nodevis[x]=1;
    for(int i=now[x];i<e[x].size();i=now[x]){
        now[x]=i+1;
        if(vis[e[x][i].id]) continue;
        vis[e[x][i].id]=1;
        //判断是不是转回来的点
        color[e[x][i].id]=x<e[x][i].v;
        dfs(e[x][i].v);
    }
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i){
        l[i]=read(),r[i]=read();
        ++r[i]; //做差分，直接+1
        a.push_back(l[i]);
        a.push_back(r[i]);
    }
    //排序+离散化
    sort(a.begin(),a.end());
    auto aed=unique(a.begin(),a.end());
    //更新l和r在离散化数组中的位置
    for(int i=1;i<=n;++i){
        l[i]=lower_bound(a.begin(),aed,l[i])-a.begin()+1;
        r[i]=lower_bound(a.begin(),aed,r[i])-a.begin()+1;
        //把l和r连边
        ++du[l[i]]; ++du[r[i]];
        e[l[i]].push_back({r[i],i});
        e[r[i]].push_back({l[i],i});
    }
    //初始化，后面dfs找欧拉回路
    vector<int> ji;
    for(int i=1;i<=2*n;++i){
        if(du[i]&1) ji.push_back(i);
    }
    int p=0,cnt=n;
    //把奇数点配对一下
    for(int i=0;i<ji.size();++i){
        if(!p){
            p=ji[i];
        }
        else{
            ++cnt;
            e[p].push_back({ji[i],cnt});
            e[ji[i]].push_back({p,cnt});
            p=0;
        }
    }
    for(int i=1;i<=2*n;++i){
        if(!du[i]) continue;
        if(!nodevis[i]) dfs(i);
    }
    for(int i=1;i<=n;++i)
        printf("%d%c",color[i]," \n"[i==n]);
    return 0;
}