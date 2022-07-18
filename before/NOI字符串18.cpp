#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
string s1,s2;
int main()
{
	cin>>s1>>s2;
	int l1=s1.size(),l2=s2.size(),flag=0;
	if(l1>l2){
		for(int i=0;i<=l1-l2;i++){
			string temp=s1.substr(i,l2);
			if(temp==s2){
				flag=1;
				break;
			}
			else flag=0;
		}
	}
	else{
		for(int i=0;i<=l2-l1;i++){
			string temp=s2.substr(i,l1);
			if(temp==s1){
				flag=2;
				break;
			}
			else flag=0;
		}
	}
	if(flag==1) cout<<s2<<" is substring of "<<s1;
	else if(flag==2) cout<<s1<<" is substring of "<<s2;
	else cout<<"No substring";
	return 0;
}

