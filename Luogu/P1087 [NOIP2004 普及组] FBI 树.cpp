#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int n;
int a[2<<11],f[2<<11];
inline int read(){
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    return c-'0';
}
void dfs(int l,int r){
    if(l>r) return;
    if(l<r){
        int mid=(l+r)>>1;
        dfs(l,mid);
        dfs(mid+1,r);
    }
    if(a[r]-a[l-1]==r-l+1) putchar('I');
    else if(a[r]-a[l-1]==0) putchar('B');
    else putchar('F');
}
int main()
{
    cin>>n;
    n=1<<n;
    for(int i=1;i<=n;++i){
        a[i]=read();
        a[i]+=a[i-1];
    }
    dfs(1,n);
    return 0;
}