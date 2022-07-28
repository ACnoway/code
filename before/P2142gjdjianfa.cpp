#include<iostream>
#include<cstdio>
#include<cstdio>
using namespace std;
int a[10088],b[10088];
string biga,bigb;
bool daxiao(int a[],int b[]){
	if(b[0]>a[0]){
		return false;
	}
	if(a[0]>b[0]){
		return true;
	}
	for(int i=a[0];i>=1;i--){
		if(b[i]>a[i]){
			return false;
		}
		if(a[i]>b[i]){
			return true;
		}
	}
	return true;
}
void jian(int a[],int b[]){
	for(int i=1;i<=a[0];i++){
		if(a[i]<b[i]){
			a[i]+=10;a[i+1]--;
		}
		a[i]-=b[i];
	}
	while(a[0]>1&&!a[a[0]]){
		a[0]--;
	}
	for(int i=a[0];i>=1;i--){
		cout<<a[i];
	}
}
int main()
{
	cin>>biga>>bigb;
	a[0]=biga.size(); b[0]=bigb.size();
	for(int i=1;i<=a[0];i++){
		a[i]=biga[a[0]-i]-'0';
	}
	for(int i=1;i<=b[0];i++){
		b[i]=bigb[b[0]-i]-'0';
	}
	if(!daxiao(a,b)){
		cout<<"-";
		jian(b,a);
	}
	else{
		jian(a,b);
	}
	return 0;
}
