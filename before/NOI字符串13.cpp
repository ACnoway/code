#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
char a[101];
int main()
{
	gets(a);
	for(int i=0;i<strlen(a);i++){
		if(islower(a[i])) a[i]-=32;
	}
	puts(a);
	return 0;
}

