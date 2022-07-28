#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string a;
int ti[301]={0}; 
int main()
{
	getline(cin,a);
	int word=0,flag=1;
	for(int i=0;i<a.size();i++){
		if(a[i]==' '&&flag==1){
			flag=0;
			word++;
			continue;
		}
		else if(a[i]==' '&&flag==0){
			continue;
		}
		else{
			flag=1;
			ti[word]++;
		}
	}
	printf("%d",ti[0]);
	for(int i=1;i<=word;i++){
		printf(",%d",ti[i]);
	}
	return 0;
}

