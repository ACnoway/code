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
int n,m,w,k;
struct cqs{
    int x,y;
}a[100005];
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
    
    return 0;
}