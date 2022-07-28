#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	double n,big=0,small=11,add=0,score[1001];
	cin>>n;
	for(int i=0;i<n;i++){//获取分数 
		double a;
		cin>>a;
		add+=a; //分数总和 
		if(a>big) big=a; //最高分 
		if(a<small) small=a; //最低分 
	}
	if(n>2){
		add=add-big-small; //减去最高分和最低分 
		cout<<fixed<<setprecision(2)<<add/(n-2); //输出 
	}
	else if(n==2) cout<<fixed<<setprecision(2)<<add/n; //等于二时直接除2 
	else if(n==1) cout<<add; //等于一时直接输出 
	else cout<<"0";
	return 0;
}

