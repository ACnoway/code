#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a>b) swap(a,b);
	if(a>c) swap(a,c);
	if(b>c) swap(b,c);
	char A,B,C;
	cin>>A>>B>>C;
	switch(A){
		case 65:cout<<a<<" ";break;
		case 66:cout<<b<<" ";break;
		case 67:cout<<c<<" ";break;
	}
	switch(B){
		case 65:cout<<a<<" ";break;
		case 66:cout<<b<<" ";break;
		case 67:cout<<c<<" ";break;
	}
	switch(C){
		case 65:cout<<a;break;
		case 66:cout<<b;break;
		case 67:cout<<c;break;
	}
	
	return 0;
}


