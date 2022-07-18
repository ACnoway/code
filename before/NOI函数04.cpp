#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[101][101],b[101][101],temp[101][101],c[101][101];
void in(int a[101][101],int h,int l){
	for(int i=0;i<h;i++){
		for(int o=0;o<l;o++){
			cin>>a[i][o];
		}
	}
}
void szcopy(int a[101][101],int b[101][101],int x,int y,int h,int l){
	for(int i=0;i<h;i++){
		for(int o=0;o<l;o++){
			b[i][o]=a[i+x][o+y];
		}
	}
}
int main()
{
	int m,n,r,s,add=0,least=99999999;
	cin>>m>>n;
	in(a,m,n);
	cin>>r>>s;
	in(b,r,s);
	for(int i=0;i<=m-r;i++){
		for(int o=0;o<=n-s;o++){
			szcopy(a,temp,i,o,r,s);
			for(int x=0;x<r;x++){
				for(int y=0;y<s;y++){
					add+=abs(b[x][y]-temp[x][y]);
				}
			}
			if(add<least){
				least=add;
				szcopy(a,c,i,o,r,s);
			}
			add=0;
		} 
	}
	for(int i=0;i<r;i++){
		for(int o=0;o<s;o++){
			printf("%d ",c[i][o]);
		}
		printf("\n");
	}
	return 0;
}

