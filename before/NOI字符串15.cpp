#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
char a[101][21];
int main()
{
	int n;
	cin>>n;
	getchar();
	for(int i=0;i<n;i++){
		gets(a[i]);
	}
	for(int i=0;i<n;i++){
		if(isalpha(a[i][0])&&islower(a[i][0])) a[i][0]-=32;
		for(int o=1;o<strlen(a[i]);o++){
			if(isalpha(a[i][o])&&isupper(a[i][o])) a[i][o]+=32;
		}
		puts(a[i]);
	}
	return 0;
}

