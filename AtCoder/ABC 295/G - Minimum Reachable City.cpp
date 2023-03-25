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
const int N=200005;
int n,q,x;
//* -----并查集
int p[N],fa[N],xiao[N];
int find(int x){
    while(p[x]!=x) x=p[x]=p[p[x]];
    return p[x];
}
void merge(int x,int y){
    int xx=find(x),yy=find(y);
    xiao[yy]=min(xiao[yy],xiao[xx]);
    p[find(x)]=find(y);
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i) p[i]=i,xiao[i]=i;
    for(int i=1;i<n;++i){
        x=read();
        fa[i+1]=x;
    }
    q=read();
    int op,u,v;
    while(q--){
        op=read();
        u=read();
        if(op==1){
            v=read();
            int xx=find(u),yy=find(v);
            if(yy>=xx) continue;
            while(xx!=yy){
                p[xx]=yy;
                xx=fa[xx];
            }
        }
        else{
            printf("%d\n",xiao[find(u)]);
        }
    }
    return 0;
}