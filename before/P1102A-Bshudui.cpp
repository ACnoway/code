#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,c,ans;
int a[200001];
void work(int l,int r){
	if(l>r) return;
	
	int mid=(l+r)/2;
	for(int i=l;i<=mid;i++){
		for(int j=r;j>mid;j--){
			if(abs(a[i]-a[j])==c){
				ans++;
			}
		}
	}
	work(mid+1,r);
	work(l,mid-1);
}
int main()
{
	cin>>n>>c;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	n--;
	for(int i=n;i>=1&&a[i]>=c;i--){
		ans+=upper_bound(a,a+n,a[i]-c)-lower_bound(a,a+n,a[i]-c);
	}
	cout<<ans;
	return 0; 
}
