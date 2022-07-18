#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int k,t1=0,t5=0,t10=0;
	cin>>k;
	for(int i=0;i<k;i++){
		int a;
		cin>>a;
		if(a==1) t1+=1;
		if(a==5) t5+=1;
		if(a==10) t10+=1;
	}
	printf("%d\n%d\n%d",t1,t5,t10);
	return 0;
}


