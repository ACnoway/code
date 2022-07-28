#include<iostream>
#include<set>
using namespace std;
int x1[101]={0},y1[101]={0},z1[101]={0},x2[101]={0},y2[101]={0},z2[101]={0},da[21][21][21]={{0},{0},{0}},lc[101]={0},lk[101]={0},lg[101]={0};
int main()
{
	int w,x,h,q,c1,k1,g1,c,k,g,cs,ks,gs;
	cin>>w>>x>>h>>q;
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
	
