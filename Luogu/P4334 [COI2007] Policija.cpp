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
const int N=100005,M=1000006;
int n,m;
vector<int> e[N],E[N];
int dfid,dfn[N],cdfn[N],low[N];
int main()
{
    n=read(); m=read();
    for(int i=1;i<=m;++i){
        int x=read(),y=read();
        e[x].push_back(y);
        e[y].push_back(x);
    }
    tarjan(1,1);
    return 0;
}