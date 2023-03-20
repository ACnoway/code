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
const int N=33004;
int n,m;
int dfid,col,dfn[N],low[N],color[N];
int top,st[N];
vector<int> e[N];
void tarjan(int x){
    dfn[x]=low[x]=++dfid;
    st[++top]=x;
    for(int v:e[x]){
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
inline int dui(int x){
    return (x&1?x+1:x-1);
}
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=m;++i){
        int x=read(),y=read();
        //x不能去就让x的同事去
        e[x].push_back(dui(y));
        e[y].push_back(dui(x));
    }
    for(int i=1;i<=2*n;++i){
        if(!dfn[i]) tarjan(i);
    }
    for(int i=1;i<=2*n;i+=2){
        if(color[i]==color[i+1]){
            printf("NIE\n");
            return 0;
        }
    }
    for(int i=1;i<=2*n;i+=2){
        if(color[i]<color[i+1]){
            printf("%d\n",i);
        }
        else printf("%d\n",i+1);
    }
    return 0;
}