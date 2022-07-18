#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std; 
void zhuan(int n,int r){
	if(n==0) return;
	int m=n%r;
	if(m<0) m-=r,n+=r;
	if(m>=10) m=m-10+'A';
	else m+='0';
	zhuan(n/r,r);
	printf("%c",m);
	return;
}
int main(){
	int n,r;
	cin>>n>>r;
	cout<<n<<"=";
	zhuan(n,r);
	cout<<"(base"<<r<<")";
	return 0;
}
