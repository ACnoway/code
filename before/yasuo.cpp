#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(false); 
	int n,a0,a1,abc=0,ti=0;
	cin>>n;
	while(1){
		cin>>a0>>a1;
		for(int i=0;i<a0;i++){
			cout<<"0";
			abc++;
			ti++;
			if(abc==n&&ti!=(n*n)){
				cout<<endl;
				abc=0;
			}
			if(ti==(n*n)) return 0;
		}
		for(int i=0;i<a1;i++){
			cout<<"1";
			abc++;
			ti++;
			if(abc==n&&ti!=(n*n)){
				cout<<endl;
				abc=0;
			}
			if(ti==(n*n)) return 0;
		}
		if(ti==(n*n)) return 0;
	}
	return 0;
}

