#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[3][10]={"Tie","Player1","Player2"};
int b[101]={0};
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s1,s2;
		cin>>s1>>s2;
		if((s1=="Rock"&&s2=="Rock")||(s1=="Scissors"&&s2=="Scissors")||(s1=="Paper"&&s2=="Paper")){
			b[i]=0;
		}
		else if((s1=="Rock"&&s2=="Scissors")||(s1=="Scissors"&&s2=="Paper")||(s1=="Paper"&&s2=="Rock")){
			b[i]=1;
		}
		else if((s1=="Rock"&&s2=="Paper")||(s1=="Scissors"&&s2=="Rock")||(s1=="Paper"&&s2=="Scissors")){
			b[i]=2;
		}
	}
	for(int i=0;i<n;i++){
		printf("%s\n",a[b[i]]);
	}
	return 0;
}

