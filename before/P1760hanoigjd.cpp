#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int b[1000001];
bool jin=false;
void jia(){
	for(int i=1;i<=b[0];i++){
		b[i]*=2;
	}
	for(int i=1;i<=b[0];i++){
		b[i+1]+=b[i]/10;b[i]%=10;
	}
	if(b[b[0]+1]){
		jin=true;
		b[0]++;
	}
}
int main()
{
	int a;
	cin>>a;
	if(!a){
		cout<<"0";
		return 0;
	}
	b[0]=1; b[1]=2;
	for(int i=0;i<a-1;i++){
		jia();
	}
	if(b[1]==0){
		if(b[b[0]]==1) b[0]--;
		for(int i=b[0];i>=1;i--){
			if(b[i]==0) b[i]=9;
			else b[i]--;
		}
	}
	else b[1]--;
	for(int i=b[0];i>=1;i--){
		cout<<b[i];
	}
	return 0;
}
