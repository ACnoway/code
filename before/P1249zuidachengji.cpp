#include<iostream>
#include<cstdio>
using namespace std;
int a[10001],num[10001];
void mul(int a[],int n){
	for(int i=1;i<=a[0];i++){
		a[i]*=n;
	}
	for(int i=1;i<=a[0];i++){
		a[i+1]+=a[i]/10;a[i]%=10;
	} 
	while(a[a[0]+1]){
		a[0]++;
		a[a[0]+1]=a[a[0]]/10;
		a[a[0]]%=10;
	}
}
int main()
{
	int n,abcd=0;
	a[0]=1;a[1]=1;
	cin>>n;
	for(int i=2;n>0;i++){
		if(n-i>=0){
			n-=i;
			num[abcd++]=i;
		}
		else break;
	}
	for(int i=0;i<abcd;i++){
		cout<<num[i]<<" ";
		mul(a,num[i]);
	}
	cout<<endl;
	for(int i=a[0];i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
