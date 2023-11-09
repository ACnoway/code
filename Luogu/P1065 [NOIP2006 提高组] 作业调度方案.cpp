#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int N=30;
int n,m,ans;
int anpai[N*N],mac[N][N],ti[N][N],now[N],st[N];
bool use[N][10004];
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
    int x=0,jq=0;
    bool flag=1;
    for(int i=1;i<=n*m;++i){
        x=anpai[i];
        jq=mac[x][++now[x]];
        for(int j=st[x];j;++j){
            if(use[jq][j]) continue;
            flag=1;
            for(int k=0;k<ti[x][now[x]];++k){
                if(use[jq][j+k]){
                    flag=0;
                    break;
                }
            }
            if(!flag) continue;
            for(int k=0;k<ti[x][now[x]];++k) use[jq][j+k]=1;
            st[x]=j+ti[x][now[x]];
            ans=max(ans,j+ti[x][now[x]]-1);
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}