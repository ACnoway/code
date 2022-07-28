#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string a;
int main()
{
	int n,ti=0,most=0,flag=1;
	cin>>n;
	cin>>a;
	if(n<2){
		cout<<"0";
		return 0;
	}
	for(int i=0;i<n-1;i++){
		if(a[i]=='V'&&a[i+1]=='K') ti++;
	}
	most=ti;
	for(int i=0;i<n;i++){
		ti=0;
		string temp=a;
		if(temp[i]=='V') temp[i]='K';
		else temp[i]='V';
		for(int o=0;o<n-1;o++){
			if(temp[o]=='V'&&temp[o+1]=='K') ti++;
		}
		if(ti>most) most=ti;
	}
	cout<<most;
	return 0;
}
