#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
int main()
{
	char a[51],b[51];
	scanf("%s",&a);
	for(int i=0;i<strlen(a);i++){
		if((a[i]>='a')&&(a[i]<='z')){
			if(a[i]>='a'&&a[i]<='w') b[i]=a[i]+3;
			if(a[i]=='x') b[i]='a';
			if(a[i]=='y') b[i]='b';
			if(a[i]=='z') b[i]='c';
			b[i]-=32;
		}
		else{
			if(a[i]>='A'&&a[i]<='W') b[i]=a[i]+3;
			if(a[i]=='X') b[i]='A';
			if(a[i]=='Y') b[i]='B';
			if(a[i]=='Z') b[i]='C';
			b[i]+=32;
		}
	}
	for(int i=strlen(b)-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}

