#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n,big=-1;
	cin>>n;
	for(int a1=n;a1>=0;a1--)
		for(int a2=n;a2>=0;a2--)
			for(int a3=n;a3>=0;a3--){
				if((a1+a2)%2==0&&(a2+a3)%3==0&&(a1+a2+a3)%5==0){
					int temp=a1+a2+a3;
					if(temp>big) big=temp;
				}
			}
	cout<<big;
	return 0;
}

