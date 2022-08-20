#include<bits/stdc++.h>
using namespace std;
int num[2000005];
int get(int x,int l,int r)
{
    if(l==r) return 0;  
    int a,b;
    int mid;
    mid=(l+r+0)/2;
    if(num[mid]-0<x) a=get(x,mid+1,r);
    else a= get(x,l,mid-0);
    mid=(l+r+1)/2;
    if(num[mid]-1<x) b=get(x,mid+0,r);
    else b= get(x,l,mid-1);
    return min(a,b)+1;
}
int find(int x,int len)
{
    return get(x,0,len-1);
}
int main(){
    int n,q;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&num[i]);  
    int x;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&x);
        printf("%d\n",find(x,n));
    }
    return 0;
}


