#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int x[10001],n[10001],a[20002],b[101]={1,1};
string bigx,bign;
void gjp(int a[],int n){
	a[1]+=n;
	for(int i=1;i<=a[0];i++){
		a[i+1]+=a[i]/10; a[i]%=10;
	}
	if(a[a[0]+1]) a[0]++;
}
void gjm(int a[],int b[]){
	for(int i=1;i<=a[0];i++){
		if(a[i]<b[i]){
			a[i]+=10; a[i+1]--;
		}
		a[i]-=b[i];
	}
	while(a[0]>0&&!a[a[0]])   
        a[0]--;
}
bool gjhw(int a[]){
	for(int i=1;i<=(a[0]+1)/2;i++){
		if(a[i]!=a[a[0]-i+1]) return false;
	}
	return true;
}
int main()
{
	int T;
	cin>>T;
	for(int shuju=0;shuju<T;shuju++){
		memset(x,0,sizeof(x)); memset(n,0,sizeof(n));
		cin>>bigx>>bign;
		x[0]=bigx.size(); a[0]=bigx.size(); n[0]=bign.size();
		for(int i=1;i<=x[0];i++){
			x[i]=bigx[i]-'0';
			a[i]=bigx[i]-'0';
		}
		for(int i=1;i<=n[0];i++){
			n[i]=bign[i]-'0';
		}
		while(n[0]){
			gjp(a,1);
			if(gjhw(a)){
				gjm(n,b);
			}
		}
		for(int i=a[0];i>=1;i--){
			cout<<a[i];
		}
	}
	return 0;
}

