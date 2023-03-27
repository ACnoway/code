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
const int N=10004;
int T,ID,n,m,x;
int a[N],fa[N];
vector<int> e[N];
int main()
{
    T=read(); ID=read();
    while(T--){
        n=read();m=read();
        for(int i=1;i<=n;++i){
            a[i]=read();
            e[i].clear();
        }
        for(int i=1;i<n;++i){
            x=read();
            fa[i+1]=x;
            e[i+1].push_back(x);
            e[x].push_back(i+1);
        }
    }
    return 0;
}