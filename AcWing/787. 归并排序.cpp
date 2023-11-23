#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int a[N],tmp[N];
void guibing(int l,int r){
    if(l>=r) return;
    int mid=(l+r)>>1;
    guibing(l,mid),guibing(mid+1,r);
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(a[i]<=a[j]) tmp[++k]=a[i++];
        else tmp[++k]=a[j++];
    }
    while(i<=mid) tmp[++k]=a[i++];
    while(j<=r) tmp[++k]=a[j++];
    for(int i=1;i<=k;++i) q[i+l-1]=tmp[i];
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    guibing(1,n);
    for(int i=1;i<=n;++i) cout<<a[i]<<' ';
    return 0;
}
