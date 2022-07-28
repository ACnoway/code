#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[33];
	scanf("%s",&a);
	int l=strlen(a);
	if(a[l-2]=='e'&&a[l-1]=='r'){
		for(int i=0;i<l-2;i++){
			cout<<a[i];
		}
	}
	else if(a[l-2]=='l'&&a[l-1]=='y'){
		for(int i=0;i<l-2;i++){
			cout<<a[i];
		}
	}
	else if(a[l-3]=='i'&&a[l-2]=='n'&&a[l-1]=='g'){
		for(int i=0;i<l-3;i++){
			cout<<a[i];
		}
	}
	else{
		puts(a);
	}
	return 0;
}

