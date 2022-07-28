#include<iostream>
using namespace std;
int main()
{
	long long n,s=0,times=1;
	cin>>n;
	for(long long i=1;i<=n;i++){
		times=1;
		cout<<"i="<<i<<endl;
		for(long long x=1;x<=i;x++){
			times*=x;
			cout<<"times="<<times<<endl;
		}
		s+=times;
		cout<<"s="<<s<<endl;
	} 
	cout<<s;
	return 0;
}

