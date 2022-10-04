#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200010;
int n,q;
int flag,ii,k,l,r;
int a[N],ans[N];
signed main(){
	scanf("%d%d",&n,&q);
	ans[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(q--){
		cin>>flag;
		if(flag==1){
			cin>>ii>>k;
			a[ii]=k;
		}
		else{
			int f,summ=1,sum=1;
			cin>>l>>r;
			for(int i=l;i<=r;i++){
				sum=1;
				f=0;
				for(int j=i;j<=r;j++){
					sum*=a[j];
					if(1073741824<sum){f=1;break;}
					summ=max(sum,summ);
				}
				if(f) break;
			}
			if(f) cout<<"Too large";
			else printf("%lld",summ);
			cout<<endl;
		}
	}
} 