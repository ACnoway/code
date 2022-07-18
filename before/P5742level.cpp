#include<iostream>
#include<cstdio>
#include<cmath>
const int N=1000;
using namespace std;
struct stu{
	int num;
	int xueye;
	int suzhi;
	double zonghe;
	int zongfen;
	int total(int xueye,int zonghe){
		return xueye+zonghe;
	}
};
stu a[N];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].num>>a[i].xueye>>a[i].suzhi;
		a[i].zonghe=a[i].xueye*0.7+a[i].suzhi*0.3;
		a[i].zongfen=a[i].total(a[i].xueye,a[i].suzhi);
	}
	for(int i=0;i<n;i++){
		if(a[i].zongfen>140&&a[i].zonghe>=80) cout<<"Excellent";
		else cout<<"Not excellent";
		cout<<endl;
	}
	return 0;
}
