#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int read(){
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
const int N=2000006;
int n,m,k;
int a[N],f[N];
int main()
{
    n=read();
    m=read();
    k=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
        f[i]=a[i]+f[i-1];
    }
    int l=1,r=k,sum=0,ans=0;
    for(int i=1;i+k-1<=n;++i){
        l=1,r=i+k-1,sum=f[i+k-1]-f[i-1];
        while(l<=n&&f[r]-f[l-1]-sum>m) ++l;
        while(r<=n&&f[r]-f[l-1]-sum<=m) ++r;
        ans=max(ans,r-l);
    }
    printf("%d\n",ans);
    return 0;
}
