#include<iostream>
using namespace std;
int main()
{
	int t,m=0;
	cin>>t;
	for(int i=1;t>0;i++){
		for(int y=1;y<=i;y++){
			m+=i;
			t--;
			if(!t){
				cout<<m; return 0;
			}
		}
	}
	cout<<m;
	return 0;
}
