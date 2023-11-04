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
const int N=30004;
int n,l;
string s[N];
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>l;
    for(int i=1;i<=n;++i){
        cin>>s[i];
    }
    int ans=0;
    bool diff=0;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            diff=0;
            for(int k=0;k<l;++k){
                if(s[i][k]!=s[j][k]&&diff){
                    diff=0;
                    break;
                }
                if(s[i][k]!=s[j][k]&&!diff) diff=1;
            }
            if(diff) ++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}