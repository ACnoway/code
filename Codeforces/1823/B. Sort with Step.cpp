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
const int N=2e5+10;
int T,n,k;
int p[N];
vector<int> a;
int main()
{
    T=read();
    while(T--){
        a.clear();
        n=read(); k=read();
        for(int i=1;i<=n;++i){
            p[i]=read();
            if(abs(p[i]-i)%k) a.emplace_back(i);
        }
        if(a.empty()){
            cout<<0<<endl;
            continue;
        }
        if(a.size()>2){
            cout<<-1<<endl;
            continue;
        }
        if(abs(p[a[0]]-a[1])%k||abs(p[a[1]]-a[0])%k) cout<<-1<<endl;
        else cout<<1<<endl;
    }
    return 0;
}