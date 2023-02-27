#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int maxn=3003;
struct node{
    int to,nxt;
}e[maxn];
int idx,head[maxn];
inline void add(int u,int v){
    e[++idx].to=v;
    e[idx].nxt=head[u];
    head[u]=idx;
}

int match[maxn],p[maxn];

int n,m,ans,w,cnt;
int lie[60],hang[60];
char a[60][60];
int top,st[maxn];

bool dfs(int u,int q){
    int v;
    for(int i=head[u];i;i=e[i].nxt){
        v=e[i].to;
        if(v==q||p[v]==w) continue;
        p[v]=w;
        //如果对方没有被匹配
        if(!match[v]){
            ans++;
            match[v]=u;
            return 1;
        }
        else{
            //如果已经被匹配就让跟对方匹配的人换个人
            if(dfs(match[v],v)){
                match[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;++i) cin>>a[i]+1;
    for(int i=0;i<=n+1;++i){
        a[i][0]='.';
        a[i][m+1]='.';
    }
    for(int i=0;i<=m+1;++i){
        a[0][i]='.';
        a[n+1][i]='.';
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i][j]=='*'&&a[i-1][j]=='.'){
                //新的一列
                lie[j]=++cnt;
                st[++top]=cnt;
            }
            if(a[i][j]=='*'&&a[i][j-1]=='.'){
                //新的一行
                hang[i]=++cnt;
                //这里不用将cnt入栈是因为对于这个二分图我们从一个集合进入dfs就行，不用管另一个
            }
            if(a[i][j]=='*'){
                add(lie[j],hang[i]);
            }
        }
    }
    for(int i=1;i<=top;++i){
        w=i;
        dfs(st[i],0);
    }
    write(ans);
    putchar('\n');
    return 0;
}