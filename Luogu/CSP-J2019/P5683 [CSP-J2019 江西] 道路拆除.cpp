#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int a[3002][3002];
int main(){
	int n,m;
	cin>>n>>m;
	memset(a,0x7f,sizeof(a));
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
	}
	int s1,t1,s2,t2;
	cin>>s1>>t1>>s2>>t2;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	if(a[1][s1]>t1||a[1][s2]>t2){
		cout<<-1<<endl;
		return 0;
	}
	if(a[1][s1]>a[1][s2]){
		if(a[1][s2]+a[s2][s1]==a[1][s1]){
			cout<<m-a[1][s1]<<endl;
			return 0;
		}
		int ans=(m-a[1][s1]-a[1][s2])<0?0:(m-a[1][s1]-a[1][s2]);
		cout<<ans<<endl;
		return 0;
	}
	if(a[1][s1]==a[1][s2]){
		int ans=(m-a[1][s1]-a[1][s2])<0?0:(m-a[1][s1]-a[1][s2]);
		cout<<ans<<endl;
		return 0;
	}
	if(a[1][s1]<a[1][s2]){
		if(a[1][s1]+a[s1][s2]==a[1][s2]){
			cout<<m-a[1][s2]<<endl;
			return 0;
		}
		int ans=(m-a[1][s1]-a[1][s2])<0?0:(m-a[1][s1]-a[1][s2]);
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}




