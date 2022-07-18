#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;
string email,acc,pass,aemail;
int main()
{
	int n,t=0;
	cin>>email>>n;
	for(int i=0;i<n;i++){
		cin>>acc>>pass>>aemail;
		if(email==aemail){
			t++;
			for(int o=0;o<pass.size();o++){
				if(isalpha(pass[o])&&islower(pass[o])) pass[o]=toupper(pass[o]);
				else if(isalpha(pass[o])&&isupper(pass[o])) pass[o]=tolower(pass[o]);
			}
			cout<<acc<<" "<<pass<<endl;
		}
	}
	if(!t) cout<<"empty";
	return 0;
}

