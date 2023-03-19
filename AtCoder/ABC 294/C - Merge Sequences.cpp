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
int n,m;
int a[100005],b[100005];
struct node{
    int v,p;
    bool operator <(const node &x)const{
        return v<x.v;
    }
}c[200005];
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=n+m;++i){
        c[i].v=read();
        c[i].p=i;
    }
    sort(c+1,c+n+m+1);
    for(int i=1;i<=n+m;++i){
        if(c[i].p>n){
            b[c[i].p-n]=i;
        }
        else a[c[i].p]=i;
    }
    for(int i=1;i<=n;++i) printf("%d ",a[i]);
    putchar('\n');
    for(int i=1;i<=m;++i) printf("%d ",b[i]);
    return 0;
}