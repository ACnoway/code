#include<iostream>
#include<cstdio>
using namespace std;
bool is_run(int year);
int main()
{
	int x,y,run[1001],ti=0;
	cin>>x>>y;
	for(int i=x;i<=y;i++){
		if(is_run(i)){
			run[ti++]=i;
		}
	}
	printf("%d\n",ti);
	for(int i=0;i<ti;i++){
		printf("%d ",run[i]);
	}
	return 0;
}
bool is_run(int year){
	if((year%4==0&&year%100!=0)||year%400==0) return true;
	else return false;
}

