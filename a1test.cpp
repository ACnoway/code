#include<iostream>
using namespace std;
int s,a[100007];//这里取的10 0000，可以取更大
//但即使对于打表来说，时间也够长的了
int main()
{
	for(int i=1;i<=100000;i++)
	{
		for(int j=1;j<=i;j++)
		if(i%j==0)//判断j是i的余数
		if(i!=j)//由题可得（仿佛是道数学题），约数没有本身
		a[i]+=j;//其约数和加上j
	}
	for(int i=1;i<=100000;i++)
	for(int j=1;j<=100000;j++)//双重循环判断
	if(a[i]==j&&a[j]==i&&i>=6&&i>j&&j>=6)cout<<i<<' '<<j<<endl;
    	//i的约数和等于j，j的约数和等于i，两者都大于6
        //这里为了方便起见是i大于j
	return 0;
}