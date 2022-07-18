#include<iostream>
#include<cstdio>
using namespace std;
struct jilu{
	bool tool;
	int price;
	int t;
}a[100002];
int ti[100002][2];
int n,front,rear,i;
long long ans;
int main(){
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i].tool>>a[i].price>>a[i].t;
	}
	for(i=0;i<n;i++){
		if(a[i].tool==0){
			ti[rear][0]=a[i].t;
			ti[rear++][1]=a[i].price;
			ans+=a[i].price;
			continue;
		}
		while(ti[front][0]+45<a[i].t&&front<rear) front++;
		//
		if(front>=rear){
			ans+=a[i].price;
			continue;
		}
		int j=front;
		while(j<rear&&ti[j][1]<a[i].price) j++;
		//
		if(j==rear){
			ans+=a[i].price;
			continue;
		}
		else if(j!=front){
			ti[j][0]=0,ti[j][1]=0;
			continue;
		}
		front++;
	}
	cout<<ans<<endl;
	return 0;
}




