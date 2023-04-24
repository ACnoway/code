#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
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
const int N=1000006;
typedef pair<int,int> pii;
int T,n,s;
int w[N],v[N];
map<int,int> m;
signed main()
{
    freopen("shopping.in","r",stdin);
    freopen("shopping.out","w",stdout);
    T=read();
    while(T--){
        m.clear();
        n=read();
        s=read();
        int ma=0;
        for(int i=1;i<=n;++i) w[i]=read(),ma=max(ma,w[i]);
        for(int i=1;i<=n;++i) v[i]=read();
        int sum=0,cnt=0,ans=0,l=max(s-ma+1,1ll),r=s;
        for(int i=1;i<=n;++i){
            vector<pii> e;
            while(m.size()&&(--m.end())->first>=w[i]){
                pii t=*(--m.end());
                m.erase(t.first);
                e.emplace_back((pii){w[i]-1,t.second});
                e.emplace_back((pii){t.first-w[i],t.second+v[i]});
            }
            for(pii t:e){
                m[t.first]=max(m[t.first],t.second);
            }
            if(w[i]<=l) l-=w[i],r-=w[i],sum+=v[i];
            else if(w[i]<=r) m[r-w[i]]=max(m[r-w[i]],sum+v[i]),r=w[i]-1;
        }
        ans=sum;
        for(pii t:m){
            ans=max(ans,t.second);
        }
        cout<<ans<<endl;
    }
    return 0;
}