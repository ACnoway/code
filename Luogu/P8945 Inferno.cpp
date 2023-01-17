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
const int maxn=10000007;
int n,k,cnt=1,ans=-maxn;
struct node{
    int v,p;
}fa[maxn],fb[maxn];
int a[maxn];
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
int get(int x){
    int l=fa[x].p,r=fb[x].p;
    return fb[r].v-fa[l].v+(r-l+1>k?k-(r-l+1-k):r-l+1);
}
int main()
{
    n=read();k=read();
    for(int i=0;i<=n;++i){
        fa[i].p=fb[i].p=i;
        fa[i].v=maxn;fb[i].v=-maxn;
    }
    for(int i=1;i<=n;++i){
        a[i]=read();
        if(!a[i]) cnt++;
        a[i]+=a[i-1];   
        fa[cnt].v=min(fa[cnt].v,a[i]);
        fb[cnt].v=max(fb[cnt].v,a[i]);
    }
    for(int i=1;i<=cnt;++i){
        if(fa[i].v>fa[i-1].v) fa[i]=fa[i-1];
    }
    for(int i=cnt;i;--i){
        if(fb[i].v<fb[i+1].v) fb[i]=fb[i+1];
    }
    for(int i=1;i<=cnt;++i){
        ans=max(ans,get(i));
    }
    write(ans);putchar('\n');
    return 0;
}