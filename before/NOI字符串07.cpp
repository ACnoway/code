#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[256],b[256];
int main()
{
	scanf("%s",&a);
	for(int i=0;i<strlen(a);i++){
		switch(a[i]){
			case 'A':{
				b[i]='T';
				break;
			}
			case 'T':{
				b[i]='A';
				break;
			}
			case 'G':{
				b[i]='C';
				break;
			}
			case 'C':{
				b[i]='G';
				break;
			}
		}
	}
	printf("%s",b);
	return 0;
}

