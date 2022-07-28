#include<iostream>
#include<cstdio>
using namespace std;
int sq[1002][1002]={0},sqt[1002][1002]={0},m1x,m1y,m2x,m2y,n;
long long eat=0;
void pac(int x,int y,int a,int b);
int main()
{
	freopen("pacman.in","r",stdin);
	freopen("pacman.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int o=1;o<=n;o++){
			cin>>sq[i][o];
		}
	}
	for(int i=1;i<=n;i++){
		for(int o=1;o<=n;o++){
			sqt[i][o]=sq[i][o];
		}
	}
	long long m1=0,m2=0;
	for(int i=1;i<=n;i++){
		for(int o=1;o<=n;o++){
			if(sq[i][o]>=m1){
				m1=sq[i][o]; m1x=i; m1y=o;
			}
		}
	}
	eat+=sqt[m1x][m1y]; sqt[m1x][m1y]=0;
	for(int i=1;i<=n;i++){
		for(int o=1;o<=n;o++){
			if(sqt[i][o]>=m2){
				m2=sqt[i][o]; m2x=i; m2y=o;
			}
		}
	}
	eat+=sqt[m2x][m2y]; sqt[m2x][m2y]=0;
	if(sqt[m1x-1][m1y-1]>=sqt[m1x-1][m1y+1]&&sqt[m1x-1][m1y-1]>=sqt[m1x+1][m1y-1]&&sqt[m1x-1][m1y-1]>=sqt[m1x+1][m1y+1]){
		pac(m1x,m1y,0,0);
	}
	else if(sqt[m1x-1][m1y+1]>=sqt[m1x-1][m1y-1]&&sqt[m1x-1][m1y+1]>=sqt[m1x+1][m1y-1]&&sqt[m1x-1][m1y+1]>=sqt[m1x+1][m1y+1]){
		pac(m1x,m1y,1,0);
	}
	else if(sqt[m1x+1][m1y-1]>=sqt[m1x-1][m1y-1]&&sqt[m1x+1][m1y-1]>=sqt[m1x-1][m1y+1]&&sqt[m1x+1][m1y-1]>=sqt[m1x+1][m1y+1]){
		pac(m1x,m1y,2,0);
	}
	else if(sqt[m1x+1][m1y+1]>=sqt[m1x-1][m1y-1]&&sqt[m1x+1][m1y+1]>=sqt[m1x-1][m1y+1]&&sqt[m1x+1][m1y+1]>=sqt[m1x+1][m1y-1]){
		pac(m1x,m1y,3,0);
	}
	if(sqt[m2x-1][m2y-1]>=sqt[m2x-1][m2y+1]&&sqt[m2x-1][m2y-1]>=sqt[m2x+1][m2y-1]&&sqt[m2x-1][m2y-1]>=sqt[m2x+1][m2y+1]){
		pac(m2x,m2y,0,1);
	}
	else if(sqt[m2x-1][m2y+1]>=sqt[m2x-1][m2y-1]&&sqt[m2x-1][m2y+1]>=sqt[m2x+1][m2y-1]&&sqt[m2x-1][m2y+1]>=sqt[m2x+1][m2y+1]){
		pac(m2x,m2y,1,1);
	}
	else if(sqt[m2x+1][m2y-1]>=sqt[m2x-1][m2y-1]&&sqt[m2x+1][m2y-1]>=sqt[m2x-1][m2y+1]&&sqt[m2x+1][m2y-1]>=sqt[m2x+1][m2y+1]){
		pac(m2x,m2y,2,1);
	}
	else if(sqt[m2x+1][m2y+1]>=sqt[m2x-1][m2y-1]&&sqt[m2x+1][m2y+1]>=sqt[m2x-1][m2y+1]&&sqt[m2x+1][m2y+1]>=sqt[m2x+1][m2y-1]){
		pac(m2x,m2y,3,1);
	}
	printf("%lld",eat);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
void pac(int x,int y,int a,int b){
	switch(a){
		case 0:{
			eat+=sqt[x][y]; sqt[x][y]=0;
			if(b==1){
				if(x-1==m2x&&y-1==m2y){
					return;
				}
			}
			else{
				if(x-1==m1x&&y-1==m1y){
					return;
				}
			}
			if(x-1!=1&&y-1!=1){
				pac(x-1,y-1,0,b); return;
			}
			else if(x-1==1&&y-1!=1){
				pac(x-1,y-1,2,b); return;
			}
			else if(x-1!=1&&y-1==1){
				pac(x-1,y-1,1,b); return;
			}
			else if(x-1==1&&y-1==1){
				eat+=sqt[x-1][y-1]; sqt[x-1][y-1]=0;
				return;
			}
			
		}
		case 1:{
			eat+=sqt[x][y]; sqt[x][y]=0;
			if(b==1){
				if(x-1==m2x&&y+1==m2y){
					return;
				}
			}
			else{
				if(x-1==m1x&&y+1==m1y){
					return;
				}
			}
			if(x-1!=1&&y+1!=n){
				pac(x-1,y+1,1,b); return;
			}
			else if(x-1==1&&y+1!=n){
				pac(x-1,y+1,3,b); return;
			}
			else if(x-1!=1&&y+1==n){
				pac(x-1,y+1,0,b); return;
			}
			else if(x-1==1&&y+1==n){
				eat+=sqt[x-1][y+1]; sqt[x-1][y+1]=0;
				return;
			}
		}
		case 2:{
			eat+=sqt[x][y]; sqt[x][y]=0;
			if(b==1){
				if(x+1==m2x&&y-1==m2y){
					return;
				}
			}
			else{
				if(x+1==m1x&&y-1==m1y){
					return;
				}
			}
			if(x+1!=n&&y-1!=1){
				pac(x+1,y-1,2,b); return;
			}
			else if(x+1==n&&y-1!=1){
				pac(x+1,y-1,0,b); return;
			}
			else if(x+1!=n&&y-1==1){
				pac(x+1,y-1,3,b); return;
			}
			else if(x+1==n&&y-1==1){
				eat+=sqt[x+1][y-1]; sqt[x+1][y-1]=0;
				return;
			}
			
		}
		case 3:{
			eat+=sqt[x][y]; sqt[x][y]=0;
			if(b==1){
				if(x+1==m2x&&y+1==m2y){
					return;
				}
			}
			else{
				if(x+1==m1x&&y+1==m1y){
					return;
				}
			}
			if(x+1!=n&&y+1!=n){
				pac(x+1,y+1,3,b); return;
			}
			else if(x+1==n&&y+1!=n){
				pac(x+1,y+1,1,b); return;
			}
			else if(x+1!=n&&y+1==n){
				pac(x+1,y+1,2,b); return;
			}
			else if(x+1==n&&y+1==n){
				eat+=sqt[x+1][y+1]; sqt[x+1][y+1]=0;cout<<"3"<<endl;
				return;
			}
			
			return;
		}
	}
}
