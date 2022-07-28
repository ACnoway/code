#include<iostream>
#include<cstdio>
using namespace std;
bool shai(int x);
int main()
{
	int num[101],n;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	for(int i=0;i<n;i++){
		if(shai(num[i])){
			cout<<num[i];
			if(i!=n-1) cout<<" ";
		}
	}
	return 0;
}
bool shai(int x){
	if(x==1) return false;
	if((x!=2&&x!=3&&x!=5&&x!=7)&&(x%2==0||x%3==0||x%5==0||x%7==0)) return false;
	for(int i=11;i<x;i+=2){
		if(x%i==0) return false;
	}
	return true;
}

