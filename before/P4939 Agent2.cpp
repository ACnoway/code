#include<iostream>
#include<cstdio>
using namespace std;
int  days[10000001];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,a,b;
		cin>>x>>a;
		if(x==0){
			cin>>b;
			for(int j=a;j<=b;j++){
				days[j]++;
			}
		}
		else{
			cout<<days[a]<<endl;
		}
	}
	return 0;
}
