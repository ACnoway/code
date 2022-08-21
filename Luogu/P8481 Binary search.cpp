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
int n,q;
int a[2000006];
int cnt;
int get(int *num,int x,int l,int r)
{
	if(l==r) return 0;
	cnt++;
    int a,b,w,mid;
    int *t=&a;
	w=0;
	mid=(l+r+w)/2;
	if(num[mid]-w<x) *t=get(num,x,mid+!w,r);
	else *t=get(num,x,l,mid-w);
    t=&b;
	w=1;
	mid=(l+r+w)/2;
	if(num[mid]-w<x) *t=get(num,x,mid+!w,r);
	else *t=get(num,x,l,mid-w);
    return min(a,b)+1;
}
int find(int *num,int x,int len)
{
	cnt=0;
	return get(num,x,0,len-1);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i];
    cin>>q;
    int x,ans;
    while(q--){
        cin>>x;
        cout<<find(a,x,n)<<endl;
    }
    return 0;
}