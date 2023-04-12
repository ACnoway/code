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
const int N=1003;
int n,ma;
int a[N],match[N];
vector<int> b;
vector<int> e[N*N];
int main()
{
    n=read();
    for(int i=0;i<=n;++i) match[i]=-1;
    for(int i=1;i<=n;++i){
        a[i]=read();
        for(int j=1;j<=n;++j){
            b.push_back(a[i]*j);
        }
    }
    ma=ma*ma;
    for(int i=1;i<=ma;++i){
        
    }
    return 0;
}