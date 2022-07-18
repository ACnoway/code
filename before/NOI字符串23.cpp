#include<iostream>
#include<cstdio>
using namespace std;
string a;
int main()
{
	int flag=1;
	getline(cin,a);
	for(int i=0;i<a.size();i++){
		if(a[i]==' '&&flag==1){
			printf("%c",a[i]);
			flag=0;
		}
		else if(a[i]==' '&&flag==0){
			continue;
		}
		else{
			printf("%c",a[i]);
			flag=1;
		}
	}
	return 0;
}

