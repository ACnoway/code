#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[100001];
int main()
{
	gets(a);
	char flag;
	bool f=false;
	for(int i=0;i<strlen(a);i++){
		int t=0;
		for(int o=0;o<strlen(a);o++){
			if(a[i]==a[o]) t++;
		}
		if(t==1){
			flag=a[i];
			f=true;
			break;
		}
	}
	if(f)
	cout<<flag;
	else
	cout<<"no";
	return 0;
}
