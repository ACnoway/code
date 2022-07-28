#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
char alphas[200];
int main()
{
	string a;
	int n;
	cin>>n>>a;
	int ti=0;
	for(int i=97;i<=122;i++){
		alphas[i]=i;
	}
	for(int i=97;i<=122;i++){
		alphas[i+26]=i;
	}
	for(int i=0;i<a.size();i++){
		printf("%c",alphas[a[i]+n]);
	}
	return 0;
}

