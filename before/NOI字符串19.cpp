#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string a,b,aa,bb;
int main()
{
	cin>>a>>b;
	aa=a+a; bb=b+b;
	int l1=a.size(),l2=b.size(),flag=0;
	if(l1>l2){
		for(int i=0;i<=aa.size()-l2;i++){
			string temp=aa.substr(i,l2);
			if(temp==b){
				flag=1;
				break;
			}
			else flag=0;
		}
	}
	else{
		for(int i=0;i<=bb.size()-l1;i++){
			string temp=bb.substr(i,l1);
			if(temp==a){
				flag=2;
				break;
			}
			else flag=0;
		}
	}
	if(flag) cout<<"true";
	else cout<<"false";
	return 0;
}

