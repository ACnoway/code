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
const int maxn=100005;
int n,m,w,k,cc;
int tmp[maxn],cnt[maxn],C[maxn][12];
struct cqs{
    int x,y;
}a[maxn];
bool cmp(cqs a,cqs b){
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
bool cmp2(cqs a,cqs b){
    if(a.y==b.y) return a.x<b.x;
    return a.y<b.y;
}
int main()
{
    n=read();
    m=read();
    w=read();
    for(int i=1;i<=w;++i){
        a[i].x=read();
        a[i].y=read();
    }
    k=read();
    sort(a+1,a+w+1,cmp);
    for(int i=0;i<=w;++i) C[i][0]=1;
    for(int i=1;i<=w;++i){
        for(int j=1;j<=min(i,k);++j)
            C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
    for(int i=1;i<=w;++i){
        if(i==1||a[i].y!=a[i-1].y) cc++;
        tmp[i]=cc;
    }
    for(int i=1;i<=w;++i) 
    return 0;
}