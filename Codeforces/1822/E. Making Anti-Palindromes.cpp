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
int T,n;
string s;
int tong[30];
signed main()
{
    cin>>T;
    while(T--){
        cin>>n>>s;
        if(n&1){
            cout<<-1<<endl;
            continue;
        }
        for(int i=0;i<30;++i) tong[i]=0;
        for(int i=0;i<n;++i){
            ++tong[s[i]-'a'];
        }
        int ma=0;
        for(int i=0;i<26;++i) ma=max(ma,tong[i]);
        if(ma>n/2){
            cout<<-1<<endl;
            continue;
        }
        int ans=0;
        for(int i=0;i<30;++i) tong[i]=0;
        for(int i=0;i<n/2;++i){
            if(s[i]==s[n-i-1]){
                ++ans;
                ++tong[s[i]-'a'];
            }
        }
        for(int i=0;i<26;++i){
            for(int j=i+1;j<26&&tong[i];++j){
                if(!tong[j]) continue;
                int jian=min(tong[i],tong[j]);
                ans-=jian;
                tong[i]-=jian;
                tong[j]-=jian;
            }
        }
        // for(int i=0;i<26;++i) ans+=tong[i];
        cout<<ans<<endl;
    }
    return 0;
}