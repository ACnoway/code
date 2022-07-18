#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string lw,sw;
char st[201];
int main()
{
	char temp;
	int ti=0,duan=999999,chang=0,dl,cl;
	do{
		scanf("%[abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ]",st);
		temp=getchar();
		int l=strlen(st);
		if(l>chang){
			lw=st; chang=l;
		}
		if(l<duan){
			sw=st; duan=l;
		} 
	}while(temp!='\n');
	cout<<lw<<endl<<sw;
	return 0;
}

