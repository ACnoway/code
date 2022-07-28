#include<iostream>
using namespace std;
int main()
{
	int m,n;
	cin>>m>>n;
	if(m%2==0) m+=1;
	if(n%2==0) n-=1;
	int xs=(n-m)/2+1;
	int he=(n+m)*((float)xs/2);
	cout<<he;
	return 0;
}


