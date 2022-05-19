#include <iostream>
#include <cstdio>
using namespace std;
bool prime(int x){
	if(x==2) return true;
	if(!(x&1)) return false;
	for(int i=3;i*i<=x;i+=2){
		if(x%i==0) return false;
	}
	return true;
}
int main()
{
	int n;
	cin>>n;
	for(int i=4;i<=n;i+=2){
		for(int j=2;j<=(i/2);++j){
			if(prime(j)&&prime(i-j)){
				cout<<i<<'='<<j<<'+'<<i-j<<endl;
				break;
			}
		}
	}
	return 0;
}