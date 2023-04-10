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
int n,l,r,ans;
int a[200005];
int sg(int a,int x,int y){
    return a%(x+y)/x;
}
int main()
{
    n=read();
    l=read();
    r=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<=n;++i){
        ans^=sg(a[i],l,r);
    }
    cout<<(ans?"First":"Second")<<'\n';
    return 0;
}