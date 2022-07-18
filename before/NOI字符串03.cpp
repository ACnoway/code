#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[501],b[501];
int main()
{
	double t;
	cin>>t;
	getchar(); gets(a); gets(b);
	double same=0,all=double(strlen(a));
	for(int i=0;i<strlen(a);i++){
		if(a[i]==b[i]) same+=1;
	}
	same=same/all;
	if(same>=t) cout<<"yes";
	else cout<<"no";
	return 0;
}
