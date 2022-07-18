#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	string x;
	int cnt=0;
	cin>>x;
	for(int i=0;i<x.size();i++)
		if(x[i]=='1') cnt++;
	cout<<cnt<<endl;
	return 0;
}




