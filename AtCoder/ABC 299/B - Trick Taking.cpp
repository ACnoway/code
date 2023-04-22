#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
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
typedef pair<int,int> pii;
int n,t;
int a[200005],b[200005];
map<int,vector<pii>> m;
int main()
{
    n=read();
    t=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<=n;++i){
        b[i]=read();
        m[a[i]].emplace_back((pii){b[i],i});
    }
    if(m[t].empty()) t=a[1];
    int ma=0,mp=0;
    for(auto i:m[t]){
        int rk=i.first,p=i.second;
        if(rk>ma){
            ma=rk;
            mp=p;
        }
    }
    cout<<mp<<endl;
    return 0;
}