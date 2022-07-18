#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
char a[81];
int main()
{
	gets(a);
	for(int i=0;i<strlen(a);i++){
		if(isalpha(a[i])){
			switch(a[i]){
				case 'z':{
					a[i]='a';
					break;
				}
				case 'Z':{
					a[i]='A';
					break;
				}
				default:{
					a[i]+=1;
					break;
				}
			}
		}
	}
	printf("%s",a);
	return 0;
}

