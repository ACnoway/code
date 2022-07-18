#include<iostream>
#include<cstdio>
#include<cmath>
const int N=1000;
using namespace std;
int most=0,pos=0;
int highest(int total1,int total2,int pos1,int pos2){
	return total2>total1?pos2:pos1;
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
		pos=highest(most,a[i].total,pos,i);
		most=a[pos].total;
	}
	cout<<a[pos].name<<" "<<a[pos].chinese<<" "<<a[pos].math<<" "<<a[pos].english;
	return 0;
}

