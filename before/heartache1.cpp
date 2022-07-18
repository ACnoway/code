#include<iostream>
using namespace std;
int ai[3001]={0};
int main()
{
	int n,m,add=0;
	cin>>n>>m;
	int a=100*m;
	for(int i=0;i<n;i++){
		cin>>ai[i];
	}
	for(int i=0;i<=n-m;i++){
		for(int t=i;t<i+m;t++){
			add+=ai[t];
		}
		if(add<a) a=add;
		add=0;
	}
	cout<<a;
 	return 0;
}

