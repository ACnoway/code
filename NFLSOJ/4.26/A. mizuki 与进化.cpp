#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
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
typedef pair<int,int> pii;
int n,ha,ta,hb,tb,hc,tc;
int d[4],a[N],b[N],c[N];
string s;
vector<pii> ans;
int main()
{
    freopen("evolution.in","r",stdin);
    freopen("evolution.out","w",stdout);
    cin>>n>>s;
    for(int i=0;i<n*2;++i){
        ++d[s[i]-'A'];
    }
    if(d[0]>n||d[1]>n||d[2]>n){
        cout<<"No"<<endl;
        return 0;
    }
    int ab=n-d[2],ac=n-d[1],bc=n-d[0];
    for(int i=0;i<n*2;++i){
        if(s[i]=='A'){
            a[++ta]=i+1;
        }
        else if(s[i]=='B'){
            b[++tb]=i+1;
        }
        else{
            if(hb<tb&&bc){
                --bc;
                ans.emplace_back((pii){b[++hb],i+1});
            }
            else{
                if(ha>=ta){
                    cout<<"No"<<endl;
                    return 0;
                }
                --ac;
                ans.emplace_back((pii){a[ta--],i+1});
            }
        }
    }
    for(int i=1;i<=ab;++i){
        if(a[ha+1]>b[hb+1]){
            cout<<"No"<<endl;
            return 0;
        }
        ans.emplace_back((pii){a[++ha],b[++hb]});
    }
    cout<<"Yes"<<endl;
    for(pii i:ans){
        cout<<i.first<<' '<<i.second<<endl;
    }
    return 0;
}