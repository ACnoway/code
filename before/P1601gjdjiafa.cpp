#include<iostream>
#include<cstdio>
#include<cstdio>
using namespace std;
int a[60000],b[60000];
string biga,bigb;
void jia(int a[],int b[]){
	for(int i=1;i<=a[0];i++){
		a[i]+=b[i];
	}
	for(int i=1;i<=a[0];i++){
		a[i+1]+=a[i]/10;a[i]%=10;
	}
	if(a[a[0]+1]) a[0]++;
	for(int i=a[0];i>=1;i--){
		if(a[i]) break;
		else a[0]--;
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
	if(a[0]<b[0]) a[0]=b[0];
	jia(a,b);
	return 0;
}
