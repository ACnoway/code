#include<iostream>
#include<cstdio>
#include<cmath>
#define un unsigned
using namespace std;
bool flag=true;
bool is_prime(un int a){
	if((a==1||a%2==0)&&a!=2) return false;
	for(un int i=3;i<sqrt(a);i+=2){
		if(a%i==0) return false;
	}
	return true;
}
int main()
{
	un int n,c;
	cin>>n;
	if(is_prime(n/2)){
		cout<<n/2; return 0;
	} 
	for(un int i=2;i<sqrt(n);i++){
		if(n%i!=0) continue;
		c=n/i;
		if(is_prime(c)){
			cout<<i; return 0;
		}
	}
	return 0;
}

