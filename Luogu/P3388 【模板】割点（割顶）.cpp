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
const int N=20004;
int n,m;
int dfid,cnt,dfn[N],low[N];
bool ge[N];
vector<int> e[N];
void tarjan(int x,int die){
    dfn[x]=low[x]=++dfid;
    int ch=0;
    for(int v:e[x]){
        //如果是树边就遍历下去
        if(!dfn[v]){
            tarjan(v,x);
            low[x]=min(low[x],low[v]);
            //如果x不是根节点，判断是否为割点
            if(low[v]>=dfn[x]&&x!=die)
                cnt+=(!ge[x]),ge[x]=1;
            //如果x是根节点，记录孩子数
            if(x==die) ch++;
        }
        //如果是回边直接更新low
        low[x]=min(low[x],dfn[v]);
    }
    if(ch>=2&&x==die) cnt+=(!ge[x]),ge[x]=1;
}
int main()
{
    n=read(); m=read();
    int x,y;
    for(int i=1;i<=m;++i){
        x=read(); y=read();
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(int i=1;i<=n;++i){
        if(!dfn[i]) tarjan(i,i);
    }
    printf("%d\n",cnt);
    for(int i=1;i<=n;++i){
        if(ge[i]) printf("%d ",i);
    }
    return 0;
}