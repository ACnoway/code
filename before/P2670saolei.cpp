#include<iostream>
#include<cstdio>
using namespace std;
char a[105][105];
int b[3]={-1,0,1};
void sout(int n,int m,char a[105][105]){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='*') cout<<a[i][j];
			else printf("%d",a[i][j]);
		}
		cout<<endl;
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]>='?') a[i][j]-='?';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='*'){
				for(int o=-1;o<=1;o++){
					for(int p=-1;p<=1;p++){
						if(a[i+o][j+p]!='*') a[i+o][j+p]+=1;
					}
				}
			}
		}
	}
	sout(n,m,a);
	return 0;
}
