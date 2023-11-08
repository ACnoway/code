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
const int N=52;
int n,m,ans=1145141919,c=1145141919;
int a[N][N],dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool vis[N][N];
void dfs(int x,int y,int sum,int cnt){
    if(sum>ans||(sum==ans&&cnt>c)) return;
    if(x>n||y>m){
        bool flag=1,yes;
        int nx,ny;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(vis[i][j]) continue;
                yes=0;
                for(int k=0;k<4;++k){
                    nx=i+dx[k],ny=j+dy[k];
                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&vis[nx][ny]){
                        yes=1;
                        break;
                    }
                }
                if(!yes){
                    flag=0;
                    break;
                }
            }
            if(!flag) break;
        }
        if(!flag) return;
        if(sum<ans) ans=sum,c=cnt;
        else if(sum==ans) c=min(c,cnt);
        return;
    }
    int xx=x,yy=y;
    if(y==m) ++x,y=1;
    else ++y;
    dfs(x,y,sum,cnt);
    vis[xx][yy]=1;
    dfs(x,y,sum+a[xx][yy],cnt+1);
    vis[xx][yy]=0;
}
int main()
{
    freopen("oil.in","r",stdin);
    freopen("oil.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            a[i][j]=read();
        }
    dfs(1,1,1,0);
    printf("%d %d",c,ans);
    return 0;
}