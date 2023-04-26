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
int a[N],b[N],c[N];
string s;
vector<pii> ans;
int main()
{
    freopen("evolution.in","r",stdin);
    freopen("evolution.out","w",stdout);
    cin>>n>>s;
    n<<=1;
    for(int i=0;i<n;++i){
        if(s[i]=='A'){
            a[++ta]=i+1;
        }
        else if(s[i]=='B'){
            b[++tb]=i+1;
        }
        else{
            if(ha<ta){
                ans.emplace_back((pii){a[ta--],i+1});
            }
            else if(hb<tb){
                ans.emplace_back((pii){b[tb--],i+1});
            }
            else c[++tc]=i+1;
        }
    }
    if(hc<tc){
        cout<<"No"<<endl;
        return 0;
    }
    while(ha<ta&&hb<tb){
        if(a[++ha]<b[++hb]){
            ans.emplace_back((pii){a[ha],b[hb]});
        }
        else{
            cout<<"No"<<endl;
            return 0;
        }
    }
    if(ha<ta||hb<tb){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    for(pii i:ans){
        cout<<i.first<<' '<<i.second<<endl;
    }
    return 0;
}