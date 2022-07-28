#include<iostream>
using namespace std;
const int maxn=100;
int n,m[maxn],shash[maxn]={0};
void allsort(int d){
	if(d==n+1){
		for(int i=1;i<=n;i++){
			cout<<m[i]<<' ';
		}
		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(shash[i]==0){
			m[d]=i;
			shash[i]=1;
			allsort(d+1);
			shash[i]=0;
		}
	}
}
int main()
{
	cin>>n;
	allsort(1);
	return 0;
}
