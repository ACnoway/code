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
	for(int i=4;i<=n;i+=2){
		for(int o=2;o<i-1;o++){
			int add=i-o;
			if(is_prime(o)&&is_prime(add)){
				printf("%d=%d+%d\n",i,o,add);
				break;
			}
		}
	}
	return 0;
}

