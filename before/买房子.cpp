#include<iostream>
using namespace std;
int main()
{
	int n,m=1,n2=0;
	double price=200.0,k;
	cin>>n>>k;
	k=k/100+1.0;
	n2+=n;
	while(n2<price){
		n2+=n;
		price*=k;
		m+=1;
		cout<<price<<" "<<n2<<" "<<m<<endl;
	}
	cout<<m;
	return 0;
}

