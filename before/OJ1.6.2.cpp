#include<iostream>
using namespace std;
int main()
{
	int apple[11]={0},tt,a=0;
	for(int i=0;i<10;i++){
		cin>>apple[i];
	}
	cin>>tt;
	tt+=30;
	for(int i=0;i<10;i++){
		if(tt>=apple[i]) a++;
	}
	cout<<a;
	return 0;
}

