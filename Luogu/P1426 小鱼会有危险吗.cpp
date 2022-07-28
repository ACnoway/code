#include <iostream>
using namespace std;
int main()
{
	double s,x,a=7.00,cnt=0.00;
	cin>>s>>x;
	while(true){
		cnt+=a;
		a*=0.98;
		if(cnt>(s-x)&&cnt<(x+x)){
			if(a+cnt>s+x){
				cout<<'n';
				return 0;
			}
			else{
				cout<<'y';
				return 0;
			}
		}
		if(cnt>100) break;
	}
	cout<<'n';
	return 0;
}