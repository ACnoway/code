#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[101],a1[101],b[101],b1[101];
int main()
{
	char ch;
	int ac=0,bc=0;
	while((ch=getchar())!='\n'){
		if(ch!=' ') a[ac++]=ch;
		else continue;
	}
	while((ch=getchar())!='\n'){
		if(ch!=' ') b[bc++]=ch;
		else continue;
	}
	int l1=strlen(a),l2=strlen(b),flag=0;
	for(int i=0;i<l1;i++){
		if(a[i]>='A'&&a[i]<='Z'){
			a1[i]=a[i]+=32;
		}
		else if(a[i]!=' '){
			a1[i]=a[i];
		}
		if(b[i]>=65&&b[i]<=90){
			b1[i]=b[i]+=32;
		}
		else if(b[i]!=32){
			b1[i]=b[i];
		}
	}
	flag=strcmp(a1,b1);
	if(flag) cout<<"NO";
	else cout<<"YES";
 	return 0;
}
