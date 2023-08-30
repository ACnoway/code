#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<climits>
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
const int N=202,inf=INT_MAX>>1;
int n,cnt,h,t;
int bl[N],q[N];
typedef pair<int,int> pii;
pii p[N];
double a[N][N],far[N],yuan[N];
bool vis[N];
char tmp[N];
inline double dis(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void bfs(int x){
    h=t=0;
    int now;
    q[++t]=x;
    bl[x]=cnt;
    vis[x]=1;
    while(h<t){
        now=q[++h];
        for(int i=1;i<=n;++i){
            if(a[now][i]!=inf&&!vis[i]){
                q[++t]=i;
                vis[i]=1;
                bl[i]=cnt;
            }
        }
    }
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i) p[i].first=read(),p[i].second=read();
    for(int i=1;i<=n;++i){
        scanf("%s",tmp);
        for(int j=1;j<=n;++j){
            if(tmp[j-1]-'0') a[i][j]=dis((double)p[i].first,(double)p[i].second,(double)p[j].first,(double)p[j].second);
            else a[i][j]=inf;
        }
        a[i][i]=0;
    }
    //floyd最短路
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    //染色法确定连通块
    for(int i=1;i<=n;++i){
        if(!bl[i]) ++cnt,bfs(i);
    }
    //找到块内最远的点
    //以及找到块内的直径
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(bl[i]==bl[j]&&a[j][i]!=inf) far[i]=max(far[i],a[j][i]);
        }
        yuan[bl[i]]=max(yuan[bl[i]],far[i]);
    }
    //枚举相连的点，记录ans
    double ans=inf;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(bl[i]!=bl[j]){
                ans=min(ans,max(yuan[bl[i]],max(yuan[bl[j]],far[i]+dis((double)p[i].first,(double)p[i].second,(double)p[j].first,(double)p[j].second)+far[j])));
            }
        }
    }
    printf("%.6lf\n",ans);
    return 0;
}