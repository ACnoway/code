#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[201],b[201];
string biga;
void add(int a[],int b[],int n){
	for(int i=1;i<=a[0];i++) a[i]+=b[i];
	for(int i=1;i<=a[0];i++){
		a[i+1]+=a[i]/n; a[i]%=n;
	}
	if(a[a[0]+1]) a[0]++;
}
void fz(int a[],int b[]){
	for(int i=1;i<=a[0];i++){
		b[a[0]-i+1]=a[i];
	}
}
bool pd(int a[],int b[]){
	for(int i=1;i<=a[0];i++){
		if(a[i]!=b[i]) return false;
	}
	return true;
}
int main()
{
	int n;
	cin>>n;
	cin>>biga;
	a[0]=biga.length();
	for(int i=1;i<=a[0];i++){
		if(biga[a[0]-i]<'A') a[i]=biga[a[0]-i]-'0';
		else a[i]=biga[a[0]-i]-'A'+10;
	}
	for(int i=0;i<30;i++){
		fz(a,b);
		if(pd(a,b)){
			cout<<"STEP="<<i;
			return 0;
		}
		add(a,b,n);
	}
	cout<<"Impossible!";
	return 0;
}
