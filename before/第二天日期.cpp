#include<iostream>
using namespace std;
int main()
{
	int y,m,d,days;
	cin>>y>>m>>d;
	switch(m){
		case 2:{
			days=28;
			if(y%4==0&&y%100!=0||y%400==0) days++;
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11:
			days=30;
			break;
		default:days=31; 
	}
	d++;
	if(d>days) d=1,m++;
	if(m>12) m=1,y++;
	cout<<y<<"-"<<m<<"-"<<d;
	return 0;
}
