#include<iostream>
using namespace std;
int sq[105][105]={{0},{0}};
int main()
{
	int n,m,k,x,y,o,p,abc=0;
	cin>>n>>m>>k;
	int mon=n*n;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		x++; y++;
		sq[y-2][x]=1;
		sq[y-1][x-1]=1;
		sq[y-1][x]=1;
		sq[y-1][x+1]=1;
		sq[y][x-2]=1;
		sq[y][x-1]=1;
		sq[y][x]=1;
		sq[y][x+1]=1;
		sq[y][x+2]=1;
		sq[y+1][x-1]=1;
		sq[y+1][x]=1;
		sq[y+1][x+1]=1;
		sq[y+2][x]=1;
	}
	for(int i=0;i<k;i++){
		cin>>o>>p;
		o++; p++;
		for(int h=-2;h<=2;h++){
			for(int l=-2;l<=2;l++){
				sq[p+h][o+l]=1;
			}
		}
	}
	n++;
	for(int i=2;i<=n;i++){
		for(int t=2;t<=n;t++){
			if(sq[i][t]==1){
				mon--;
			}
		}
	}
	cout<<mon;
	return 0;
}

