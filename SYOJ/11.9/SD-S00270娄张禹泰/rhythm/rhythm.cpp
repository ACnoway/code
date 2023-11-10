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
const int N=20,inf=1<<28;
int n,m,c,sx,sy,tx,ty,ans=inf,ma;
int a[N][N],dx[4]={0,1,-1,0},dy[4]={1,0,0,-1};
void dfs(int ti,int x,int y,int cnt){
    // debug(ti);
    if(abs(tx-x)+abs(ty-y)+ti>ans) return;
    if(cnt==c){
        ans=min(ans,abs(tx-x)+abs(ty-y)+ti);
        return;
    }
    // debug(x); debug(y); debug(endl);
    if(ti%a[x][y]==0) ++cnt;
    ++ti;
    for(int i=0;i<4;++i){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>0&&nx<=n&&ny>0&&ny<=m) dfs(ti,nx,ny,cnt);
    }
    dfs(ti,x,y,cnt);
}
int main()
{
    freopen("rhythm.in","r",stdin);
    freopen("rhythm.out","w",stdout);
    n=read();
    m=read();
    c=read();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j) a[i][j]=read(),ma=max(ma,a[i][j]);
    }
    sx=read(),sy=read();
    tx=read(),ty=read();
    ans=ma*c+n+m;
    dfs(0,sx,sy,0);
    printf("%d\n",ans);
    return 0;
}