#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	float all,pack1,price1,pack2,price2,pack3,price3;
	cin>>all>>pack1>>price1>>pack2>>price2>>pack3>>price3;
	int all1=ceil(all/pack1)*price1,all2=ceil(all/pack2)*price2,all3=ceil(all/pack3)*price3;
	if(all1<=all2&&all1<=all3) cout<<all1;
	else if(all2<=all1&&all2<=all3) cout<<all2;
	else if(all3<=all2&&all3<=all1) cout<<all3;
	return 0;
 }

