#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;
int main()
{
	char a[21];
	bool flag=false;
	gets(a);
	if(isdigit(a[0])){
		flag=false;
	}
	else{
		for(int i=0;i<strlen(a);i++){
			if((a[i]>=65&&a[i]<=90)||(a[i]>=97&&a[i]<=122)||(a[i]>=48&&a[i]<=57)||a[i]=='_'){
				flag=true;
				continue;
			}
			else{
				flag=false;
				break;
			}
		}
	}
	if(flag){
		cout<<"yes";
	}
	else{
		cout<<"no";
	}
	return 0;
}

