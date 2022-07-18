#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
int main()
{
	int n,x=100,k=1,add=0;
	cin>>n;
	while(true){
		for(int i=0;i<7;i++){ //一周筹得的钱数 
			add=add+x+i*k;
		}
		add*=52; //52周总共筹得的钱数 
		if(add!=n) { //如果52周总共筹得的钱数不等于n 
			x--; //x-1 
			if(x==0){
				x=x+100; //x重置 
				k++; //k+1 
			}
			add=0; //add重置 
		}
		else break; //如果52周总共筹得的钱数等于n，跳出while，输出 
	}
	cout<<x<<endl<<k;
	return 0;
}
