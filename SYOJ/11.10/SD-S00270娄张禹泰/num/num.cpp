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
const int N=100005;
int T,n;
int a[N];
bool vis[N];
vector<int> b;
int main()
{
    freopen("num.in","r",stdin);
    freopen("num.out","w",stdout);
    T=read();
    while(T--){
        b.clear();
        for(int i=1;i<N;++i) vis[i]=0;
        n=read();
        for(int i=1;i<=n;++i){
            a[i]=read();
            vis[a[i]]=1;
            b.push_back(a[i]);
        }
        printf("%d\n",n);
    }
    return 0;
}