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
int n,m,d;
bool flag;
int xs[N];
int a[N<<1][3];
char h[N<<1][3];
int dfid,col,dfn[N],low[N],color[N];
int top,st[N];
string s;
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
    if(dfn[x]==low[x]){
        color[x]=++col;
        while(st[top]!=x){
            color[st[top]]=col;
            --top;
        }
        --top;
    }
}
//* -----work
inline void clean(){
    dfid=col=top=0;
    for(int i=0;i<=2*n;++i){
        dfn[i]=low[i]=color[i]=st[i]=0;
        e[i].clear();
    }
}
inline int che(int k,char c){
    if(s[k]=='a'){
        if(c=='B') return k;
        else return k+n;
    }
    else if(s[k]=='b'){
        if(c=='A') return k;
        else return k+n;
    }
    else{
        if(c=='A') return k;
        return k+n;
    }
}
inline int dui(int x){
    return (x>n?x-n:x+n);
}
bool work(){
    clean();
    int x,y;
    char hx,hy;
    for(int i=1;i<=m;++i){
        x=a[i][1]; hx=h[i][1];
        y=a[i][2]; hy=h[i][2];
        //如果第x个地图没法用类型为hx的赛车就跳过
        if(s[x]==hx+32) continue;
        int nx=che(x,hx),ny=che(y,hy);
        if(s[y]==hy+32){
            e[nx].push_back(dui(nx));
        }
        else{
            //要不就都选
            e[nx].push_back(ny);
            //要不就都不选，注意这里要反着来因为要确定关系
            e[dui(ny)].push_back(dui(nx));
        }
    }
    for(int i=1;i<=2*n;++i){
        if(!dfn[i]) tarjan(i);
    }
    for(int i=1;i<=n;++i){
        if(color[i]==color[i+n]) return 0;
    }
    return 1;
}
void dfs(int k){
    //枚举到第k个x
    if(k>d){
        //枚举完了
        flag=work();
        return;
    }
    //分别枚举A和B的情况
    s[xs[k]]='a';
    dfs(k+1);
    if(flag) return;
    s[xs[k]]='b';
    dfs(k+1);
}
int main()
{
    n=read(); read();
    cin>>s;
    debug(s);
    s=' '+s;
    for(int i=1;i<=n;++i){
        //记录地图类型为x的位置
        if(s[i]=='x') xs[++d]=i;
    }
    m=read();
    for(int i=1;i<=m;++i){
        a[i][1]=read();
        h[i][1]=getchar();
        a[i][2]=read();
        h[i][2]=getchar();
    }
    dfs(1);
    if(!flag){
        printf("-1\n");
        return 0;
    }
    for(int i=1;i<=n;++i){
        //判断是什么类型的地图然后根据2-sat输出结果
        if(s[i]=='a'){
            if(color[i]<color[i+n]) putchar('B');
            else putchar('C');
        }
        else if(s[i]=='b'){
            if(color[i]<color[i+n]) putchar('A');
            else putchar('C');
        }
        else{
            if(color[i]<color[i+n]) putchar('A');
            else putchar('B');
        }
    }
    return 0;
}