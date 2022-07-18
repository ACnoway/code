#include<iostream>
#include<cstdio>
#include<cmath>
const int N=1000;
using namespace std;
bool same(int chi,int math,int eng,int total){
	if(chi<=5&&math<=5&&eng<=5&&total<=10) return true;
	else return false;
}
struct stu{
	string name;
	int chinese;
	int math;
	int english;
	int total;
};
stu a[N];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].name>>a[i].chinese>>a[i].math>>a[i].english;
		a[i].total=a[i].chinese+a[i].math+a[i].english;
	}
	for(int i=0;i<n;i++){
		for(int o=i+1;o<n;o++){
			if(same(abs(a[i].chinese-a[o].chinese),abs(a[i].math-a[o].math),abs(a[i].english-a[o].english),abs(a[i].total-a[o].total))){
				cout<<a[i].name<<" "<<a[o].name<<endl;
			}
		}
	}
	return 0;
}

