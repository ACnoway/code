#include<iostream>
#include<cstdio>
using namespace std;
int a[28];
long long frac(int x){
	long long res=1;
	while(x) res*=x--;
	return res;
}
int main(){
	int n,ji=0,zm=0;
	cin>>n;
	for(int i=0;i<n;++i){
		char x;
		cin>>x;
		++a[x-'a'];
	}
	long long ans=1;
	for(int i=0;i<26;++i){
		if(a[i]==0) continue;
		ans*=frac(a[i]);
		if(a[i]&1){
			--a[i];
			++ji;
		}
	}
	long long f=frac(n);
	if((ji>0&&!(n&1))||(ji>1&&(n&1))){
		cout<<f<<endl;
		return 0;
	}
	ans*=frac(n/2); 
	cout<<f-ans<<endl;
	return 0;
}




