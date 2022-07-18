#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int t=0,temp,a[16],ti=0;
	do{
		cin>>temp;
		a[t++]=temp;
	}while(temp!=0);
	t--;
	for(int i=0;i<t-1;i++){
		for(int j=i+1;j<t;j++){
			if((a[i]%a[j]==0&&a[i]/a[j]==2)||(a[j]%a[i]==0&&a[j]/a[i]==2)) ti++;
		}
	}
	cout<<ti;
	return 0;
}
