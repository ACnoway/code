#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
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
int n,m,q,cnt;
int a[N],b[N],aa[N],bb[N];
inline bool da(int &x,int &y){
    if(x>=y) return 0;
    if(b[x]==a[bb[x]]) --cnt;
    x=y;
    return 1;
}
inline bool hang(int &x,int &y){
    if(a[x]>=y) return 0;
    if(a[x]==b[aa[x]]) --cnt;
    a[x]=y;
    return 1;
}
inline bool lie(int &x,int &y){
    if(b[x]>=y) return 0;
    if(b[x]==a[bb[x]]) --cnt;
    b[x]=y;
}
signed main()
{
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
    n=read(),m=read();
    q=read();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            int x=read();
            if(da(a[i],x)) aa[i]=0,aa[i]+=j;
            if(da(b[j],x)) bb[j]=0,bb[j]+=i;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i]==b[j]) ++cnt;
        }
    }
    while(q--){
        int x=read(),y=read(),t=read();
        if(hang(x,t)) aa[x]=y;
        if(lie(y,t)) bb[y]=x;
        if(a[x]==b[y]) ++cnt;
        printf("%d\n",cnt);
    }
    return 0;
}