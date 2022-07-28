#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n<0){  //判断负数 
		cout<<"-";  //取负号 
		n=-n;  //转为正数，利于接下来的程序 
	}
	if(n%10==0) n=n/10;  //判断结尾有无0 
	int sum=0;
	while (n!=0)
	{
		int k=n%10;  //取n的个位 
		sum=sum*10+k;  //赋值，以加法的方式，可以省掉查0的时间 
		n=n/10; //减掉个位 
	}
	cout<<sum;
	return 0;
}
