#include<iostream>
#include<cstdio>
using namespace std;
void qsort(int,int);
int a[100001];
int main()
{
	int n,i;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	qsort(1,n);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
void qsort(int l,int r){
	int i,j,mid,p;
	i=l;j=r;
	mid=a[(l+r)/2];
	do{
		while(a[i]<mid) i++;
		while(a[j]>mid) j--;
		if(i<=j){
			p=a[i];a[i]=a[j];a[j]=p;
			i++;j--;
		}
	}while(i<=j);
	if(l<j) qsort(l,j);
	if(i<r) qsort(i,r);
}

