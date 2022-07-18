#include<iostream>
#include<set>
using namespace std;
int x1[100]={0},y1[100]={0},z1[100]={0},x2[100]={0},y2[100]={0},z2[100]={0},da[20][20][20]={{0},{0},{0}};
int main()
{
	int q,w,x,h,c1,k1,g1,c,k,g,cs,ks,gs;
	cin>>w>>x>>h;
	cin>>q;
	int a=w*x*h,b=0,abc=0;
	for(int i=0;i<q;i++){
		cin>>x1[i]>>y1[i]>>z1[i]>>x2[i]>>y2[i]>>z2[i];
		for(int t=x1[i];t<=x2[i];t++){
			for(int o=y1[i];o<=y2[i];o++){
				for(int p=z1[i];p<=z2[i];p++) da[t-1][o-1][p-1]=1;
			}
		}
	}
	for(int i=0;i<w;i++){
		for(int o=0;o<x;o++){
			for(int p=0;p<h;p++){
				if(da[i][o][p]==1) b++;
			}
		}
	}
	cout<<a-b;
    return 0;
}
