#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
int main()
{
	int x,n,add=0;
	cin>>x>>n;
	for(int i=0;i<n;i++){
		if(x==6) { 
			x++;continue;
		}
		if(x==7) {
			x=1;continue;
		}
		else add+=250;
		x++;
		
	}
	cout<<add;
	return 0;
}

