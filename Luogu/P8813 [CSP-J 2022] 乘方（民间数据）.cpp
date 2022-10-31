#include<iostream>
#include<cmath>
using namespace std;
unsigned long long a,b,ans=1;
int main()
{
	cin>>a>>b;
	while(b){
		ans*=a;
		b--;
		if(ans>1000000000){
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<ans<<endl;
	return 0;
}