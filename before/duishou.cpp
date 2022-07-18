#include<iostream>
#include<cmath>
using namespace std;
struct stu{
	int chi;
	int math;
	int eng;
	int total;
};
stu a[1001];
int main()
{
	int n,total,same=0,c,t=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].chi>>a[i].math>>a[i].eng;
		a[i].total=a[i].chi+a[i].math+a[i].eng;
	}
	for(int i=0;i<n;i++){
		for(int o=i+1;o<n;o++){
			if(abs(a[i].chi-a[o].chi)<=5&&abs(a[i].math-a[o].math)<=5&&abs(a[i].eng-a[o].eng)<=5&&abs(a[i].total-a[o].total)<=10){
				same++;
			}
		}
	}
	cout<<same; 
    return 0;
}

