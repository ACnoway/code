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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int maxn=200005;
int p[maxn],siz[maxn],u[maxn],v[maxn],dian[maxn],bian[maxn];
int n,m;
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
void merge(int x,int y){
    int xx=find(x),yy=find(y);
    if(xx==yy) return;
    if(siz[xx]>siz[yy]) swap(xx,yy);
    p[xx]=yy;
    siz[xx]+=siz[yy];
    siz[yy]=siz[xx];
}
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;++i) p[i]=i;
    for(int i=1;i<=m;++i){
        u[i]=read();
        v[i]=read();
        merge(u[i],v[i]);
    }
    for(int i=1;i<=n;++i){
        dian[find(i)]++;
    }
    for(int i=1;i<=m;++i){
        bian[find(u[i])]++;
    }
    for(int i=1;i<=n;++i){
        if(dian[i]!=bian[i]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}