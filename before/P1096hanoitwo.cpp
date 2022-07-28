#include<iostream>
using namespace std;
int a[5001];
void mul(int n,int a[]){
	for(int i=1;i<=a[0];i++){
		a[i]*=n;
	}
	for(int i=1;i<=a[0];i++){
		a[i+1]+=a[i]/10; a[i]=a[i]%10;
	}
	if(a[a[0]+1]) a[0]++;
}
int main()
{
	int n;
	cin>>n;
	a[0]=1;a[1]=1;
	for(int i=1;i<=n;i++){
		mul(2,a);
	}
	a[1]--;
	mul(2,a);
	for(int i=a[0];i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
