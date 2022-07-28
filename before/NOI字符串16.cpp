#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
char a[81],b[81];
int main()
{
	gets(a); gets(b);
	int l1=strlen(a),l2=strlen(b),flag=0;
	for(int i=0;i<l1;i++){
		if(a[i]>=65&&a[i]<=90){
			a[i]+=32;
		}
		if(b[i]>=65&&b[i]<=90){
			b[i]+=32;
		}
	}
	flag=strcmp(a,b);
	if(flag>0) cout<<">";
	else if(flag==0) cout<<"=";
	else cout<<"<";
 	return 0;
}

