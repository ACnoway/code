#include<iostream>
#include<algorithm>
using namespace std;
int a[100005],d1[100005],d2[100005];
int main()
{
    int n=0;
    while(cin>>a[++n]);
    n--;
    int l1=1,l2=1;
    d1[1]=a[1]; d2[1]=a[1];
    for(int i=2;i<=n;i++){
        if(d1[l1]>=a[i]) d1[++l1]=a[i];
        else{
        	int p1=upper_bound(d1+1,d1+l1+1,a[i],greater<int>())-d1;
        	d1[p1]=a[i];
		}
		if(d2[l2]<a[i]) d2[++l2]=a[i];
        else{
        	int p2=lower_bound(d2+1,d2+l2+1,a[i])-d2;
        	d2[p2]=a[i];
		}
    }
    cout<<l1<<endl<<l2;
    return 0;
}