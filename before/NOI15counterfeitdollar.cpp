#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string a[3][3];
int num[12];
bool check(int x,int y){
	int sl=0,sr=0,r=1;
	for(int i=0;i<12;i++) num[i]=1;
	num[y]=x*2;
	for(int i=0;i<3;i++){
		sl=0;sr=0;
		for(int j=0;j<a[i][0].length();j++) sl+=num[a[i][0][j]-'A'];
		for(int j=0;j<a[i][1].length();j++) sr+=num[a[i][1][j]-'A'];
		if(a[i][2]=="even"&&sl!=sr||a[i][2]=="up"&&sl<=sr||a[i][2]=="down"&&sl>=sr) r=0;
	}
	return r;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int o=0;o<3;o++){
			for(int j=0;j<3;j++){
				cin>>a[o][j];
			}
		}
		for(int o=0;o<2;o++){
			for(int j=0;j<12;j++){
				if(check(o,j))printf("%c is the counterfeit coin and it is %s.\n",j+'A',(i==1)?"heavy":"light");
			}
		}
	}
	return 0;
}

