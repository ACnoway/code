#include<iostream>
using namespace std;
int a[2][17]={{284,1210,2924,5564,6386,10856,14595,18416,66992,71145,76084,87633,88730},{220,1184,2620,5020,6232,10744,12285,17296,66928,67095,63020,69615,79750}};
int s;
int main()
{
	cin>>s;
	for(int i=0;i<=15;i++)
	{
		if(a[1][i]>=s){cout<<a[1][i]<<' '<<a[0][i];return 0;}
        	//小数大于s，输出小数，再大数
		if(a[0][i]>=s){cout<<a[0][i]<<' '<<a[1][i];return 0;}
        	//大数大于s，输出大数，再小数t
	}
    
	return 0;
}