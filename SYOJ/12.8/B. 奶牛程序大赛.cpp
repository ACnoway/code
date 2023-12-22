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
const int N=100005;
int n,h,l,r;
int a[N],b[N];
int main()
{
    n=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    long long ans=0;
    for(int i=1;i<=n;++i){
        while(l<r&&(double)b[l+1]<((double)a[i]*0.9)) ++l;
        ans+=r-l;
        b[++r]=a[i];
    }
    printf("%lld\n",ans);
    return 0;
}
