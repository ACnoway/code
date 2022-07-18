#include<iostream>
#include<cmath>
#define UN unsigned
using namespace std;
int main()
{
	int cishu;
	cin>>cishu;
	for(int cishu1=0;cishu1<cishu;cishu1++){
		UN long long in,l=1,r=18446744073709551615;
		while(1){
			UN long long mid=l/2+r/2;
			cout<<mid<<endl;
			cin>>in;
			if(in==-1) l=mid+1;
			else if(in==1) r=mid-1;
			else if(in==0) break;
		}
	}
	return 0;
}
