#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int N=1e5+10;
int n,k,x;
int a[N];
long long f[N];
int search(int v){
    int l=1,r=n,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(a[mid]<v) l=mid+1;
        else r=mid;
    }
    return l;
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    for(int i=n;i;--i){
        f[i]=f[i+1]+(long long)a[i];
    }
    k=read();
    int p;
    for(int i=1;i<=k;++i){
        x=read();
        p=search(x);
        if(a[p]<x) printf("0\n");
        else printf("%lld\n",f[p]-(long long)x*(long long)(n-p+1));
    }
    return 0;
}