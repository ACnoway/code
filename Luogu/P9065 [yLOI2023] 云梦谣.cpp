#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#define int long long
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
const int inf=1145141919;
struct node{
    int x,y,dis;
}t[9000006];
int n,m,k,nx,ny,ans=inf;
int a[3003][3003],b[3003][3003];
bool v[3003][3003];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void bfs(int xs,int ys){
    queue<node> q;
    node p;
    q.push({xs,ys,0});
    v[xs][ys]=1;
    int nx,ny;
    while(!q.empty()){
        p=q.front();
        debug(p.x);debug(p.y);
        q.pop();
        if(b[p.x][p.y]) t[b[p.x][p.y]].dis=p.dis;
        for(int i=0;i<4;++i){
            nx=p.x+dx[i];ny=p.y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m||!a[nx][ny]||v[nx][ny]) continue;
            q.push({nx,ny,p.dis+1});
            v[nx][ny]=1;
            if(xs==1&&ys==1&&nx==n&&ny==m) ans=min(ans,p.dis+1);
            else if(xs==n&&ys==m&&nx==1&&ny==1) ans=min(ans,p.dis+1);
            debug(ans);
        }
    }
}
signed main()
{
    n=read();m=read();k=read();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j) a[i][j]=read();
    }
    for(int i=1;i<=k;++i){
        t[i].x=read();t[i].y=read();
        b[t[i].x][t[i].y]=i;
        t[i].dis=inf;
    }
    bfs(n,m);
    int mi=inf,mp=0;
    for(int i=1;i<=k;++i){
        if(t[i].dis<mi) mi=t[i].dis,mp=i;
    }
    for(int i=1;i<=k;++i) t[i].dis=inf;
    for(int i=0;i<=n;++i) for(int j=0;j<=m;++j) v[i][j]=0;
    bfs(1,1);
    int tm=mi,tp=mp;
    mi=inf;mp=0;
    for(int i=1;i<=k;++i){
        if(t[i].dis<mi) mi=t[i].dis,mp=i;
    }
    bool flag=0;
    for(int i=0;i<4;++i){
        if(t[tp].x+dx[i]==t[mp].x&&t[tp].y+dy[i]==t[mp].y){
            flag=1;
            break;
        }
    }
    if(k==0||flag&&a[t[tp].x][t[tp].y]!=a[t[mp].x][t[mp].y]) write(ans);
    else if(a[t[tp].x][t[tp].y]!=a[t[mp].x][t[mp].y]) write(tm+mi+2);
    else write(tm+mi+1);
    return 0;
}