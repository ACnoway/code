#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#define int long long
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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int maxn=500005;
int n,k,L,R;
int a[maxn],sum[maxn],st[26][maxn];
inline int query(int x,int y){
    int z=log2(y-x+1);
    int xl=st[z][x],xr=st[z][y-(1<<z)+1];
    return sum[xl]>sum[xr]?xl:xr;
}
class node{
    public:
        int x,l,r,t;
        node(int _x,int _l,int _r):x(_x),l(_l),r(_r),t(query(l,r)){}
        bool operator <(const node &u)const{
            return sum[t]-sum[x-1]<sum[u.t]-sum[u.x-1];
        }
};
priority_queue<node> q;
signed main()
{
    n=read();k=read();L=read();R=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
        st[0][i]=i;
        sum[i]=sum[i-1]+a[i];
    }
    int xl,xr;
    for(int j=1;(1<<j)<=R-L+1;++j){
        for(int i=1;i+(1<<j)-1<=n;++i){
            xl=st[j-1][i],xr=st[j-1][i+(1<<(j-1))];
            st[j][i]=sum[xl]>sum[xr]?xl:xr;
        }
    }
    for(int i=1;i+L-1<=n;++i){
        q.push(node(i,i+L-1,min(i+R-1,n)));
    }
    int ans=0;
    while(k--){
        node p=q.top();
        q.pop();
        ans+=sum[p.t]-sum[p.x-1];
        if(p.l<p.t) q.push(node(p.x,p.l,p.t-1));
        if(p.t<p.r) q.push(node(p.x,p.t+1,p.r));
    }
    write(ans);
    putchar('\n');
    return 0;
}