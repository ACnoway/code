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
const int N=10004;
int n,m,query[102];
int maxp[N],siz[N],rt,cnt=0,sum,d[N],bl[N],a[N];
bool vis[N],ans[102];
typedef pair<int,int> pii;
vector<pii> e[N];
void getrt(int x,int die,int sizn){
    //找重心，这样分治时候的复杂度会从O(n)->O(logn)
    siz[x]=1;
    maxp[x]=0;
    for(auto i:e[x]){
        int v=i.first;
        //vis标记了之前已经分治完的
        if(v==die||vis[v]) continue;
        getrt(v,x,sizn);
        siz[x]+=siz[v];
        //找最大的子树大小
        maxp[x]=max(maxp[x],siz[v]);
    }
    //他之前的树的大小也要算进去
    maxp[x]=max(maxp[x],sizn-siz[x]);
    //如果比当前选的根要小就更新
    if(!rt||maxp[x]<maxp[rt]) rt=x;
}
bool cmp(int x,int y){
    //这里按照距离排序
    return d[x]<d[y];
}
void getdis(int x,int die,int dis,int from){
    //当前根可以到达的点
    a[++cnt]=x;
    //这个点到当前根的距离
    d[x]=dis;
    //这个点属于哪颗子树
    bl[x]=from;
    for(auto i:e[x]){
        int v=i.first,w=i.second;
        if(v==die||vis[v]) continue;
        //往下记录距离
        getdis(v,x,dis+w,from);
    }
}
void calc(int x){
    //计算答案，根据题目要求自己改
    //更改根，初始化
    cnt=0;
    a[++cnt]=x;
    bl[x]=x;
    d[x]=0;
    for(auto i:e[x]){
        int v=i.first,w=i.second;
        if(vis[v]) continue;
        //先把跟根相连的距离都找一遍
        getdis(v,x,w,v);
    }
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=m;++i){
        //分别处理每个询问
        if(ans[i]) continue;
        //如果这个询问在之前根的分治中已经找出来了就跳过
        int l=1,r=cnt;
        //因为之前按照距离排好序了，这里有点类似莫队转移lr的思想
        while(l<r){
            if(d[a[l]]+d[a[r]]>query[i]) --r;//距离大了就缩缩
            else if(d[a[l]]+d[a[r]]<query[i]) ++l;//距离小了就跳到下一个
            else if(bl[a[l]]==bl[a[r]]){
                //距离等于询问的但属于同一颗子树，这样的话就不能用d数组算距离了
                //判断是否相等跳到下一个情况
                if(d[a[r]]==d[a[r-1]]) --r;
                else ++l;
            }
            else{
                //相等且不属于同一颗子树的话就记录ans跳出
                ans[i]=1;
                break;
            }
        }
    }
}
void solve(int x){
    vis[x]=1;
    calc(x);
    for(auto i:e[x]){
        int v=i.first;
        if(vis[v]) continue;
        rt=0;
        getrt(v,0,siz[v]);
        solve(rt);
    }
}
int main()
{
    n=read();
    m=read();
    for(int i=1;i<n;++i){
        int u=read(),v=read(),w=read();
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    for(int i=1;i<=m;++i){
        query[i]=read();
    }
    maxp[0]=sum=n;
    getrt(1,0,n);
    solve(rt);
    for(int i=1;i<=m;++i){
        if(ans[i]) cout<<"AYE"<<endl;
        else cout<<"NAY"<<endl;
    }
    return 0;
}