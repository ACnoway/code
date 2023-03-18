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
int n,a,cnt;
bool vis[200005];
int main()
{
    n=read();
    for(int i=1;i<=n;++i){
        a=read();
        if(!vis[i]) vis[a]=1;
    }
    for(int i=1;i<=n;++i){
        if(!vis[i]) cnt++;
    }
    printf("%d\n",cnt);
    for(int i=1;i<=n;++i){
        if(!vis[i]) printf("%d ",i);
    }
    return 0;
}