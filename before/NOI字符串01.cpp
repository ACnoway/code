#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
int main()
{
	char a[256];
	int add=0;
	gets(a);
	for(int i=0;i<strlen(a);i++){
		if(isdigit(a[i])) add++;
	}
	cout<<add;
	return 0;
}

