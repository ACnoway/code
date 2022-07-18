#include<iostream>
#include<algorithm>
using namespace std;
struct stu{
	int total;
	int yw;
	int sx;
	int yy;
	int xh;
} *a;
bool cmp(stu a,stu b){
	if(a.total>b.total) return true;
	if(a.total<b.total) return false;
	if(a.yw>b.yw) return true;
	if(a.yw<b.yw) return false;
	if(a.xh<b.xh) return true;
	if(a.xh>b.xh) return false;
}
int main(){
	int n;
	cin>>n;
	a=new stu [n];
	for(int i=0;i<n;i++){
		cin>>a[i].yw>>a[i].sx>>a[i].yy;
		a[i].xh=i+1;a[i].total=a[i].yw+a[i].sx+a[i].yy;
	}
	sort(a,a+n,cmp);
	for(int i=0;i<5;i++){
		cout<<a[i].xh<<" "<<a[i].total<<endl; 
	}
	return 0;
}
