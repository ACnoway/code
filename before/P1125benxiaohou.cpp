#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
int main()
{
	string a;
	int maxm=0,minn=101,maxa,flag=0;
	cin>>a;
	for(int i=0;i<a.size();i++){
		int ti=0;
		for(int o=0;o<a.size();o++){
			if(a[i]==a[o]) ti++;
		}
		if(ti>maxm) maxm=ti;
		if(ti<minn) minn=ti;
	}
	maxa=maxm-minn;
	for(int x=1;x<=maxa;x++){
			if(maxa%x==0) flag++;
	}
	if(flag==2){
		printf("Lucky Word\n%d",maxa);
	}
	else printf("No Answer\n0");
	return 0;
}

