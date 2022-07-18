#include<iostream>
using namespace std;
int main()
{
	int m,n,add=0;
	cin>>m>>n;
	for(int i=m;i<=n;i++){
		if(i%17==0) add+=i;
	}
	cout<<add;
	return 0;
}
