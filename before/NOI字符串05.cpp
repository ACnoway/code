#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[101],s[101];
void qp();
int main()
{
	gets(s);
	for(int i=0;i<(strlen(s)-1);i++){
		a[i]=s[i]+s[i+1];
	}
	a[strlen(s)-1]=s[strlen(s)-1]+s[0];
	printf("%s",a);
	return 0;
}

