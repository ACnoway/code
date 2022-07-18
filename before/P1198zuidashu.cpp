#include<iostream>
using namespace std;
int a[200001];
int main()
{
	int n,d,top=0,tail,t=0;
	cin>>n>>d;
	for(int cishu=0;cishu<n;cishu++){
		char cz;
		int num;
		cin>>cz>>num;
		if(cz=='A'){
			a[++top]=num+t;
		}
		else if(cz=='Q'){
			
		} 
	}
	return 0;
}
