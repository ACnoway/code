#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int a[2005][2005];
long long f[2005][2005];
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			f[i][j]=a[i][j]; 
		}
	}
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<m;j++){
			f[j][i]=min(f[j][i+1],f[(j+1)%m][i+1])+a[j][i];
		}
	}
	long long ans=99999999;
	for(int i=0;i<m;i++) ans=min(ans,f[i][0]);
	cout<<ans<<endl;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}




