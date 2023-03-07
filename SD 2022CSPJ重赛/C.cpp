#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int maxn=1000006;
int n,m,q;
//a[]最开始的兵力
//gen[i]是第一个操作的懒标记，记录以i为根的子树加了多少
//zw[i]是第二个操作的懒标记，记录与i直接相连的点加了多少
int a[maxn],gen[maxn],zw[maxn];
//链式前向星存边
struct node{
    int to,nxt;
}e[maxn<<1];
int id,head[maxn];
void addedge(int u,int v){
    e[++id].to=v;
    e[id].nxt=head[u];
    head[u]=id;
}
//x表示当前节点，jia表示从父辈传下来的要加的，fa表示x的爹是谁
void dfs(int x,int jia,int fa){
    //先把传下来的jia给它加上自己的lt准备传下去
    jia+=gen[x];
    //然后把要加的先加到自己身上
    a[x]+=jia+zw[x];
    //然后就是遍历跟x相连的所有边
    int y;
    for(int i=head[x];i;i=e[i].nxt){
        y=e[i].to;
        //因为是无向边所以要注意不能回到x的爸了
        if(y==fa){
            //记得把x的zw的懒标记给它爹加上
            //(其实这个在循环外面加也行不过都一样了)
            a[fa]+=zw[x];
            continue;
        }
        //搜索下一个，记得把第二操作的懒标记加上
        a[y]+=zw[x];
        dfs(y,jia,x);
    }
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    int p,x,y;
    for(int i=1;i<n;++i){
        x=read();
        y=read();
        addedge(x,y);
        addedge(y,x);
    }
    m=read();
    while(m--){
        p=read();
        x=read();
        y=read();
        if(p==1){
            //以x为根的子树中加y，直接打个懒标记，最后询问的时候统计
            gen[x]+=y;
        }
        else{
            //还是懒标记
            zw[x]+=y;
        }
    }
    //dfs来力！
    dfs(1,0,0);
    q=read();
    while(q--){
        x=read();
        printf("%d\n",a[x]);
    }
    return 0;
}