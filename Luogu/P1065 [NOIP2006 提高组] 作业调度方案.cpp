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
const int N=10004;
int n,m;
int anpai[N*N],mac[N][N],ti[N][N],now[N],mt[N],st[N];
bool use[N][N];
int main()
{
    m=read();
    n=read();
    for(int i=1;i<=n;++i) st[i]=1;
    for(int i=1;i<=n*m;++i) anpai[i]=read();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            mac[i][j]=read();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            ti[i][j]=read();
    for(int i=1;i<=n*m;++i){
        int x=anpai[i];
        ++now[x];
        int jq=mac[x][now[x]];
        for(int j=st[x];j;++j){
            if(use[jq][j]) continue;
            bool flag=1;
            for(int k=0;k<ti[x][now[x]];++k){
                if(use[jq][j+k]){
                    flag=0;
                    break;
                }
            }
            if(!flag) continue;
            for(int k=0;k<ti[x][now[x]];++k) use[jq][j+k]=1;
            st[x]=j+ti[x][now[x]];
            mt[jq]=max(mt[jq],j+ti[x][now[x]]-1);
            break;
        }
    }
    int ans=0;
    for(int i=1;i<=m;++i) ans=max(ans,mt[i]);
    printf("%d\n",ans);
    return 0;
}