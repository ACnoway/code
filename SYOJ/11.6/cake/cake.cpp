#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
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
const int N=30004,M=100005;
int n,m;
int a[M],lmt[N];
bool vis[M];
priority_queue<int,vector<int>,greater<int> > q;
int main()
{
    freopen("cake.in","r",stdin);
    freopen("cake.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;++i) lmt[i]=read();
    for(int i=1;i<=m;++i){
        a[i]=read();
    }
    sort(a+1,a+m+1);
    int now=1,ans=0,tmp=0,ttmp=0;
    for(int i=1;i<=n;++i){
        while(q.size()&&q.top()+8<i) q.pop();
        while(now<=m&&a[now]+8<i) ++now;
        while(tmp<m&&a[tmp+1]<=i) ++tmp;
        // debug(t-h);
        ttmp=tmp;
        while(q.size()<lmt[i]&&tmp>=now&&a[tmp]<=i){
            if(vis[tmp]){
                --tmp;
                continue;
            }
            q.push(a[tmp]);
            vis[tmp]=1;
            --tmp;
            ++ans;
        }
        tmp=ttmp;
    }
    printf("%d\n",ans);
    return 0;
}
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO zyb Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%
// %%%stO xhx Orz%%%