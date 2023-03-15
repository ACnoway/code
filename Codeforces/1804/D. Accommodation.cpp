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
int n,m,ans,ama,lianxu,nlianxu,cnt;
string s;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>s;
        lianxu=nlianxu=cnt=0;
        for(int j=0;j<m;++j) cnt+=(s[j]-'0');
        for(int j=0;j+1<m;++j){
            if(s[j]=='1'&&s[j+1]=='1'){
                ++lianxu;
                ++j;
            }
        }
        for(int j=0;j+1<m;++j){
            if(s[j]=='0'||s[j+1]=='0'){
                ++nlianxu;
                ++j;
            }
        }
        ans+=cnt-min(lianxu,m/4);
        ama+=cnt-max(0,m/4-nlianxu);
    }
    cout<<ans<<' '<<ama<<endl;
    return 0;
}