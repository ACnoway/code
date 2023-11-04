#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int N=30004,base=1331,p=1145141;
int n,m;
string s[N];
int a[N],llg[202];
typedef pair<int,int> pii;
map<int,int> tong;
int qp(int a,int b){
    int res=1;
    while(b){
        if(b&1) res*=a,res%=p;
        a*=a,a%=p;
        b>>=1;
    }
    return res;
}
signed main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    llg[0]=1;
    for(int i=1;i<=200;++i) llg[i]=llg[i-1]*base%p;
    for(int i=1;i<=n;++i){
        cin>>s[i];
        for(int j=0;j<m;++j){
            a[i]=(a[i]*base%p+s[i][j]-'a')%p;
        }
    }
    int ans=0;
    for(int l=0;l<m;++l){
        tong.clear();
        for(int i=1;i<=n;++i){
            int move=qp(llg[m-l-1],p-2);
            int jian=a[i]*move%p*llg[m-l-1]%p;
            int qian=a[i]*move%p*507009%p*llg[m-l-1]%p,hou=(a[i]+p-jian)%p;
            tong[(qian+hou)%p]++;
        }
        for(auto i:tong){
            if(i.second>1) ans+=(i.second+1)*i.second/2;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}