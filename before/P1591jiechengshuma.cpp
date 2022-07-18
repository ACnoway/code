#include<iostream>
#include<cstring>
const int M=100001;
using namespace std;
long long a[M];
void mul(long long a[],int n);
void jc(int n){
	for(int i=2;i<=n;i++){
		mul(a,i);
	}
}
void mul(long long a[],int n){
	for(int o=1;o<=a[0];o++){
			a[o]*=n;
	}
	for(int i=1;i<=a[0];i++){
		a[i+1]+=a[i]/10;a[i]=a[i]%10;
	}
	while(a[a[0]+1]){
		a[0]++;
		a[a[0]+1]=a[a[0]]/10;
		a[a[0]]%=10;
	}
}
int times[11];
int main()
{
	int t,n,m,abc=0;
	cin>>t;
	for(int ti=1;ti<=t;ti++){
		cin>>n>>m;
		memset(a,0,sizeof(a));
		a[0]=1;a[1]=1;
		jc(n);
		for(int i=a[0];i>=1;i--){
			if(a[i]==m) times[abc]++;
		}
		abc++;
	}
	for(int i=0;i<abc;i++){
		cout<<times[i]<<endl;
	}
	return 0;
}
