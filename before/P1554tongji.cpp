#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int num[11]={0},n,m;
	scanf("%d%d",&m,&n);
	for(int i=m;i<=n;i++){
		if(i>=1000000000){
			num[i/1000000000%10]++;
		}
		if(i>=100000000){
			num[i/100000000%10]++;
		}
		if(i>=10000000){
			num[i/10000000%10]++;
		}
		if(i>=1000000){
			num[i/1000000%10]++;
		}
		if(i>=100000){
			num[i/100000%10]++;
		}
		if(i>=10000){
			num[i/10000%10]++;
		}
		if(i>=1000){
			num[i/1000%10]++;
		}
		if(i>=100){
			num[i/100%10]++;
		}
		if(i>=10){
			num[i/10%10]++;
		}
		if(i>=1){
			num[i/1%10]++;
		}
	}
	for(int i=0;i<10;i++){
		printf("%d ",num[i]);
	}
	return 0;
}
