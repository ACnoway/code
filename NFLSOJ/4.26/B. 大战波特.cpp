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
const int N=1000010;
int n,x,r,p,k,rc,pc;
string s;
int vp[N],vr[N],val[N];
bool cmp(int x,int y){
    return x>y;
}
signed main()
{
    freopen("bot.in","r",stdin);
    freopen("bot.out","w",stdout);
    cin>>n>>x>>r>>p>>k>>s;
    int ans=0;
    for(int i=0;i<n;++i){
        if(s[i]=='0') vp[++pc]=(n-i)*p;
        else vr[++rc]=(n-i)*(r+p);
        ans+=x-rc*r;
    }
    merge(vp+1,vp+pc+1,vr+1,vr+rc+1,val+1,cmp);
    for(int i=1;i<=k;++i) ans+=val[i];
    cout<<ans<<endl;
    return 0;
}