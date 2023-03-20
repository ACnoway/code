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
int n,m;
int col,dfid,dfn[N],low[N],color[N];
int top,st[N];
vector<int> e[N];
void tarjan(int x){
    dfn[x]=low[x]=++dfid;
    st[++top]=x;
    for(auto v:e[x]){
        if(!dfn[v]){
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }
        else if(!color[v]) low[x]=min(low[x],dfn[v]);
    }
    if(low[x]==dfn[x]){
        color[x]=++col;
        while(st[top]!=x){
            color[st[top]]=col;
            --top;
        }
        --top;
    }
}
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=m;++i){
        int x=read(),a=read(),y=read(),b=read();
        //因为要确定关系，又是两者中至少一个，那我们取反一个另一个就一定得选
        //这样就可以建边
        e[x+(a^1)*n].push_back(y+b*n);
        e[y+(b^1)*n].push_back(x+a*n);
    }
    //这里记得是2n因为有两个条件
    for(int i=1;i<=2*n;++i){
        if(!dfn[i]) tarjan(i);
    }
    for(int i=1;i<=n;++i){
        if(color[i]==color[i+n]){
            //在一个强连通分量里肯定就无解
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }
    printf("POSSIBLE\n");
    for(int i=1;i<=n;++i){
        //
        if(color[i]<color[i+n]) printf("0 ");
        else printf("1 ");
    }
    putchar('\n');
    return 0;
}