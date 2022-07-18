#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a+b>c&&c+b>a&&a+c>b) cout<<"yes";
	else cout<<"no";
	return 0;
}
