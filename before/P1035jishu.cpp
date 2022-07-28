#include<iostream>
#include<cmath>
using namespace std;
double sn=0,n=0;
void jishu(int k){
	sn+=1/++n;
	if(sn>k){
		cout<<n;
		return;
	}
	else jishu(k);
}
int main()
{
	int k;
	cin>>k;
	jishu(k);
	return 0;
}
