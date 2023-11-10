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
const int N=200005,mod=998244353;
int n,a,b,ans;
bool vis[N];
void dfs_20(int x){
    if(x>n){
        bool flag=1;
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                if(!vis[i]||!vis[j]) continue;
                int x=max(i,j),y=min(i,j);
                if(x%y==0){
                    int k=x/y;
                    if(k==a||k==b){
                        flag=0;
                        break;
                    }
                }
            }
            if(!flag) break;
        }
        if(flag) ++ans,ans%=mod;
        return;
    }
    dfs_20(x+1);
    vis[x]=1;
    dfs_20(x+1);
    vis[x]=0;
}
int main()
{
    freopen("exc.in","r",stdin);
    freopen("exc.out","w",stdout);
    n=read();
    a=read();
    b=read();
    if(a==1&&b==1){
        printf("%d\n",n);
        return 0;
    }
    dfs_20(1);
    printf("%d\n",ans);
    return 0;
}