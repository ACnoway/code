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
		x1[i]--; y1[i]--; z1[i]--; x2[i]--; y2[i]--; z2[i]--;
	}
	for(int i=0;i<q;i++){
		for(int t=x1[i];t<=x2[i]&&t<w;t++) lc[abc++]=t;
		cout<<lc[abc-1]<<endl;
	}
	abc=0;
	for(int i=0;i<q;i++){
		for(int t=y1[i];t<=y2[i]&&t<x;t++) lk[abc++]=t;
	}
	abc=0;
	for(int i=0;i<q;i++){
		for(int t=z1[i];t<=z2[i]&&t<h;t++) lg[abc++]=t;
	}
	cs=sizeof(lc)/4; ks=sizeof(lk)/4; gs=sizeof(lg)/4;
	for(int i=0;i<cs;i++){
		for(int o=0;o<ks;o++){
			for(int p=0;p<gs;p++){
				da[lk[o]][lc[i]][lg[p]]=1;
			}
		}
	}
	for(int i=0;i<=h;i++){
		for(int o=0;o<=x;o++){
			for(int p=0;p<=w;p++){
				if(da[i][o][p]==1) b++;
			}
		}
	}
	cout<<a-b;
	return 0;
}
