#include<iostream>
#include<cmath>
const int money=300;
using namespace std;
int main()
{
	int cun=0,ys[12],yu=0,m=1;
	for(int i=0;i<12;i++){
		cin>>ys[i];
	} 
	do {
		yu=yu+(money-ys[m-1]);
		if(yu/100>=1) { cun=cun+yu/100*100;yu=yu-yu/100*100; }
		m++;
	} while(yu>=0&&m<=12);
	if(yu<0) cout<<"-"<<m-1;
	else if(yu>=0) {
		cun=cun*1.2+yu;
		cout<<cun;
	}
	return 0;
}

