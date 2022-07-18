#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[2002],b[2002],c[4004];
string biga,bigb;
void cheng(int a[],int b[]){
	c[0]=a[0]+b[0]-1;
	for(int ia=1;ia<=a[0];ia++){
		for(int ib=1;ib<=b[0];ib++){
			c[ia+ib-1]+=a[ia]*b[ib];
		}	
	}
	for(int i=1;i<=c[0];i++){
		c[i+1]+=c[i]/10;c[i]%=10;
	}
	if(c[c[0]+1]) c[0]++;
	for(int i=c[0];i>=1;i--){
		cout<<c[i];
	}
}
int main()
{
	cin>>biga>>bigb;
	a[0]=biga.size();b[0]=bigb.size();
	for(int i=1;i<=a[0];i++){
		a[i]=biga[a[0]-i]-'0';
	}
	for(int i=1;i<=b[0];i++){
		b[i]=bigb[b[0]-i]-'0';
	}
	if(a[a[0]]==0||b[b[0]]==0){
		cout<<"0";
		return 0;
	}
	cheng(a,b);
	return 0;
}
