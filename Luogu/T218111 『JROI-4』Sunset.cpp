#include<cstdio>
#include<iostream>
using namespace std;
int ans[505];
int main(){
	int t,n;
	int l,r;
	cin>>t;
	int u,y;
	while(t--){
		cin>>n;
		for(int i=n;i>0;--i){
			l=1;
			r=n;
			cout<<"? 1 "<<n<<endl;
			cin>>u;
			while(l!=r){
				cout<<"? 1 "<<(l+r>>1)<<endl;
				cin>>y;
				if(y<u)l=(l+r>>1)+1;
				else r=(l+r>>1);
			}
			ans[l]=i;
			cout<<"? 2 "<<l<<endl;
		}
		cout<<"!";
		for(int i=1;i<=n;++i)cout<<" "<<ans[i];
		cout<<endl;
	}
	return 0;
}
