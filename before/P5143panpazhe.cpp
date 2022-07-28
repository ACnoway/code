#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct point{
	int x;
	int y;
	int z;
};
point a[50000];
bool cmp(point a,point b){
	return a.z<b.z;
}
int main()
{
	int n;
	cin>>n;
	double all=0;
	for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n-1;i++){
		all+=sqrt(pow(a[i].x-a[i+1].x,2)+pow(a[i].y-a[i+1].y,2)+pow(a[i].z-a[i+1].z,2));
	}
	printf("%.3lf",all);
	return 0;
}
