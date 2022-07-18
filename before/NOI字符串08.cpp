#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[31],b,c,bt,ct;
	scanf("%s%c%c%c%c",&a,&bt,&b,&ct,&c);
	for(int i=0;i<strlen(a);i++){
		if(a[i]==b) a[i]=c;
	}
	printf("%s",a);
	return 0;
}

