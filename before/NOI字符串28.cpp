#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[101][101];
string b;
int main()
{
	char temp;
	int flag=1,ti=0,t=0;
	getline(cin,b);
	for(int i=0;i<b.size();i++){
		if(b[i]!='\0'&&b[i]!=' '){
			a[ti][t++]=b[i]; flag=0;
		}
		else if(b[i]==' '){
			flag=1;
			ti++;
			t=0;
		}
		else{
			break;
		}
	}
	for(int i=ti;i>=0;i--){
		printf("%s ",a[i]);
	}
	return 0;
}
