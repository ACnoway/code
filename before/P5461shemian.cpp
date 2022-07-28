#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int a[1026][1026]={{1},{1}};
void work(int u,int m,int d,int l,int r){
	for(int i=u;i<=m;i++){
		for(int o=l;o<=(l+r)/2;o++){
			a[i][o]=0;
		}
	}
	if(u==m||l>=r) return;
	work(m+1,(m+1+d)/2,d,l,(l+r)/2);
	work(u,(u+m)/2,(u+d)/2,(l+r)/2+1,r);
	work(m+1,(m+1+d)/2,d,(l+r)/2+1,r);
}
int main()
{
	for(int i=0;i<1026;i++){
		for(int o=0;o<1026;o++){
			a[i][o]=1;
		}
	}
	int n;
	cin>>n;
	n=pow(2,n);
	work(1,n/2,n,1,n);
	for(int i=1;i<=n;i++){
		for(int o=1;o<=n;o++){
			cout<<a[i][o]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
