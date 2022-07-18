#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[10000000];
int main()
{
	for(int i=0;a[i-1]!='E';i++){
		scanf("%c",&a[i]);
	}
	if(strlen(a)==1){
		cout<<"0:0"<<endl<<endl<<"0:0";
		return 0;
	}
	int h=0,d=0,flag=1;
	for(int i=0;i<strlen(a);i++){
		if(a[i]=='W') h++;
		if(a[i]=='L') d++;
		if(h-d>=2||d-h>=2)
			if(h>=11||d>=11){
				cout<<h<<":"<<d<<endl;
				h=0; d=0;
				flag--;
			}
	}
	if(h||d) cout<<h<<":"<<d<<endl;
	else if(flag==0) cout<<"0:0"<<endl;
	h=0;d=0;
	cout<<endl;
	for(int i=0;i<strlen(a);i++){
		if(a[i]=='W') h++;
		if(a[i]=='L') d++;
		if(h-d>=2||d-h>=2)
			if(h>=21||d>=21){
				cout<<h<<":"<<d<<endl;
				h=0; d=0;
			}
	}
	if(h||d) cout<<h<<":"<<d<<endl;
	return 0;
}
