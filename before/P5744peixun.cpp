#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct stu{
	string name;
	int year;
	int score;
};
stu a[1000];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].name>>a[i].year>>a[i].score;
	}
	for(int i=0;i<n;i++){
		a[i].year++; a[i].score*=1.2;
		if(a[i].score>600){
			a[i].score=600;
		}
		cout<<a[i].name<<" "<<a[i].year<<" "<<a[i].score<<endl;
	}
	return 0;
}

