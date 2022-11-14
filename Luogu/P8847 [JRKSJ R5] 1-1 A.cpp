#include<iostream>
using namespace std;
int n,c1,c2,x;
int main()
{
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>x;
		if(x==1) c1++;
		else c2++;
	}
	bool flag=c1>c2;
	while(c1>c2){
		cout<<"1 ";
		c1--;
	}
	while(c2>c1){
		cout<<"-1 ";
		c2--;
	}
	if(flag)
		for(int i=0;i<c1;++i) cout<<"-1 1 ";
	else
		for(int i=0;i<c1;++i) cout<<"1 -1 ";
	return 0;
}