#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll mb[200002];
int main()
{
	int n,f;
	cin>>n>>f;
	for(int i=1;i<=n;i++){
		cin>>mb[i];
	}
	for(int i=0;i<f;i++){
		int x;
		cin>>x;
		switch(x){
			case 1:{
				ll l,r,k;
				cin>>l>>r>>k;
				for(int j=l;j<=r;j++){
					mb[j]+=k;
				}
				break;
			}
			case 2:{
				ll k;
				cin>>k;
				mb[1]+=k;
				break;
			}
			case 3:{
				ll k;
				cin>>k;
				mb[1]-=k;
				break;
			}
			case 4:{
				ll l,r,k;
				ll add=0;
				cin>>l>>r>>k;
				for(int j=l;j<=r;j++){
					add+=mb[j];
				}
				cout<<add<<endl;
				break;
			}
			case 5:{
				cout<<mb[1]<<endl;
				break;
			}
		}
	}
	return 0;
}
