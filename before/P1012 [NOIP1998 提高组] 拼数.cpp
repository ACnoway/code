#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool cmp(string a,string b){
	return a>b;
}
int main()
{
	string a[25];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]+='1';
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i].length()-1;j++){
			cout<<a[i][j];
		}
	}
	return 0;
}
