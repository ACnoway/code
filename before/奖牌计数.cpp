#include<iostream>
using namespace std;
int main()
{
	int n,j=0,y=0,t=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		j+=a;
		y+=b;
		t+=c;
	} 
	int z=j+y+t;
	cout<<j<<" "<<y<<" "<<t<<" "<<z;
	return 0;
}


