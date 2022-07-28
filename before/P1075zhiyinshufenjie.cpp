#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool is_prime(int a){
	int flag=0;
	for(int i=2;i<=sqrt(a);i++){
		if(a%i==0) flag++;
	}
	return flag?false:true;
}
int main()
{
	int n;
	cin>>n;
	for(int i=n;i>=1;i--){
		if(n%i==0){
			if(is_prime(i)){
				cout<<i;
				break;
			}
		}
	}
	return 0;
}
