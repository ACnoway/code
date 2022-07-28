#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool is_prime(int a){
	int flag=0;
	if(a%2==0) return false;
	for(int i=3;i<=sqrt(a);i+=2){
		if(a%i==0) return false;
	}
	return true;
}
bool pd(int a){
	int temp=a,temp1=0;
	while(temp){
		temp1*=10; temp1+=temp%10; temp/=10;
	}
	if(temp1==a) return true;
	else return false;
}
int main()
{
	int a,b,t=0;
	scanf("%d%d",&a,&b);
	if(a%2==0) a++;
	if(b%2==0) b--;
	for(int i=a;i<=b;i+=2){
		if((i>=10&&i<100&&i!=11)||(i>=1000&&i<10000)||(i>=100000&&i<1000000)||(i>=10000000&&i<100000000)) continue; 
		if(pd(i)){
			if(is_prime(i)){
				printf("%d\n",i);
			}
		}
	}
	return 0;
}

