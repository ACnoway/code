#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long double r,m;
	int y;
	cin>>r>>m>>y;
	r=r/100.0+1;
	for(int i=0;i<y;i++){
		m*=r;
	}
	m=floor(m);
	cout<<m;
	return 0;
}

