#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int n,a[101]={0},b[1001]={0};
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int mid=ceil((float)n/2.0)+10;
	int l=mid-1,r=mid+1;
	b[mid]=a[0];
	bool left=true;
	for(int i=1;i<n;i++){
		if(left){
			b[l--]=a[i];
			left=false;
		}
		else{
			b[r++]=a[i];
			left=true;
		}
	}
	for(int i=l+1;i<r;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
