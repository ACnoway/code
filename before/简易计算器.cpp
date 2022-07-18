#include<iostream>
using namespace std;
int main()
{
	int a,b;
	char c;
	cin>>a>>b>>c;
	switch(c){
		case 43:cout<<a+b;break;
		case 45:cout<<a-b;break;
		case 42:cout<<a*b;break;
		case 47:{
			if(b==0) cout<<"Divided by zero!";
			else cout<<(float)a/b;
			break;
		}
		default:cout<<"Invalid operator!";
	}
	return 0;
}

