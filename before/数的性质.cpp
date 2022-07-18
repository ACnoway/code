#include<iostream>
using namespace std;
int main()
{
	int x;
	cin>>x;
	if(x%2==0&&x>4&&x<=12) cout<<"1 ";
	else cout<<"0 ";
	if(x%2==0||(x>4&&x<=12)) cout<<"1 ";
	else cout<<"0 ";
	if(x%2==0&&!(x>4&&x<=12)) cout<<"1 ";
	else if(!(x%2==0)&&(x>4&&x<=12)) cout<<"1 ";
	else cout<<"0 ";
	if(x%2!=0&&(x<4||x>12)) cout<<"1 ";
	else cout<<"0 ";
	return 0;
}

