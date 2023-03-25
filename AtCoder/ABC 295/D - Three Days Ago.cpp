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
int ans;
int f[500005],cnt[3000];
string s;
signed main()
{
    cin>>s;
    for(int i=1;i<=s.size();++i) f[i]=f[i-1]^(1<<(s[i-1]-'0'+1));
    ++cnt[0];
    for(int i=1;i<=s.size();++cnt[f[i++]]){
        ans+=cnt[f[i]];
    }
    printf("%lld\n",ans);
    return 0;
}