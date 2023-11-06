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
const int N=200005;
int n,t,a,b,ans=1145141919;
int s[N];
void dfs(int i,int x,int y,int sum){
    if(sum>ans) return;
    if(i>t){
        ans=min(ans,sum);
        return;
    }
    dfs(i+1,s[i],y,sum+abs(s[i]-x));
    dfs(i+1,x,s[i],sum+abs(s[i]-y));
    dfs(i+1,s[i],s[i],sum+abs(s[i]-x)+abs(s[i]-y));
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    n=read();
    t=read();
    a=read();
    b=read();
    for(int i=1;i<=t;++i) s[i]=read();
    dfs(1,min(a,b),max(a,b),0);
    printf("%d\n",ans);
    return 0;
}