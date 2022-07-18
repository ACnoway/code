#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long a[5001];
int main()
{
	freopen("P1007_2.in","r",stdin);
	long long l,n,minn=0,maxx=0;
	cin>>l>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>(l/2)&&a[i]<=l&&a[i]>0){
			minn=max(minn,l+1-a[i]);
			maxx=max(maxx,l+1-a[i]);
		}
		else if(a[i]<=(l/2)&&a[i]<=l&&a[i]>0){
			maxx=max(maxx,a[i]-0);
			minn=max(minn,a[i]-0);
		}
	}
	cout<<minn<<" "<<maxx;
	fclose(stdin);
	return 0;
}
