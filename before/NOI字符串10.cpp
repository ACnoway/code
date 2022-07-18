#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
char a[201];
int main()
{
	gets(a);
	for(int i=0;i<strlen(a);i++){
		switch(a[i]){
			case 'A':{
				a[i]='V';
				break;
			}
			case 'B':{
				a[i]='W';
				break;
			}
			case 'C':{
				a[i]='X';
				break;
			}
			case 'D':{
				a[i]='Y';
				break;
			}
			case 'E':{
				a[i]='Z';
				break;
			}
			case 'F':{
				a[i]='A';
				break;
			}
			case 'G':{
				a[i]='B';
				break;
			}
			case 'H':{
				a[i]='C';
				break;
			}
			case 'I':{
				a[i]='D';
				break;
			}
			case 'J':{
				a[i]='E';
				break;
			}
			case 'K':{
				a[i]='F';
				break;
			}
			case 'L':{
				a[i]='G';
				break;
			}
			case 'M':{
				a[i]='H';
				break;
			}
			case 'N':{
				a[i]='I';
				break;
			}
			case 'O':{
				a[i]='J';
				break;
			}
			case 'P':{
				a[i]='K';
				break;
			}
			case 'Q':{
				a[i]='L';
				break;
			}
			case 'R':{
				a[i]='M';
				break;
			}
			case 'S':{
				a[i]='N';
				break;
			}
			case 'T':{
				a[i]='O';
				break;
			}
			case 'U':{
				a[i]='P';
				break;
			}
			case 'V':{
				a[i]='Q';
				break;
			}
			case 'W':{
				a[i]='R';
				break;
			}
			case 'X':{
				a[i]='S';
				break;
			}
			case 'Y':{
				a[i]='T';
				break;
			}
			case 'Z':{
				a[i]='U';
				break;
			}
		}
	}
	printf("%s",a);
	return 0;
}

