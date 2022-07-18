#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
char mi[101],yuan[101],pw[27],need[101];
int main()
{
	scanf("%s",&mi); getchar();
	scanf("%s",&yuan); getchar();
	scanf("%s",&need);
	if(strlen(mi)<26){ 
		cout<<"Failed"; return 0;
	}
	for(int i=0;i<strlen(mi);i++){
		if(isalpha(pw[mi[i]-65])){
			if(pw[mi[i]-65]!=yuan[i]){
				cout<<"Failed"; return 0;
			}
		}
		else{
			pw[mi[i]-65]=yuan[i];
		}
	}
	for(int i=0;i<strlen(pw);i++){ 
		int t=0;
		for(int o=0;o<strlen(pw);o++){
			if(pw[i]==pw[o]) t++;
		}
		if(t>=2){
			cout<<"Failed"; return 0;
		}
	}
	for(int i=0;i<strlen(need);i++){
		cout<<pw[need[i]-65];
	}
	return 0;
}

