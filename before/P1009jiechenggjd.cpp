#include<iostream>
#include<cmath>
using namespace std;
int a[101],b[101];
void mul(int *a,int *b,int *c){//c=a*b;
	c[0]=a[0]+b[0]-1;
	for(int ia=1;ia<=a[0];ia++)
	for(int ib=1;ib<=b[0];ib++){
		c[ia+ib-1]+=a[ia]*b[ib];
	}
	for(int i=1;i<=c[0];i++){
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	if(c[c[0]+1) c[0]++;
}
void jc(int a){
	if(a==1) return;
	else mul(a,jc(a-1));
}
void add(int *a, int *b){
	a[0]=max(a[0],b[0]);
	for(int i=1;i<=a[0];i++){
		a[i]+=b[i];
	}
	for(int i=1;i<=a[0];i++){
		a[i+1]+=a[i]/10;a[i]%=10;
	} 
	if(a[a[0] + 1]) a[0]++;	
}

int main()
{
	long long n,s=0,times=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		jc(i);
		add(a,b);
	} 
	cout<<s;
	return 0;
}

