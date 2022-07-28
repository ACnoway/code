#include<iostream>
#include<cstdio>
using namespace std;
struct patient{
	string name;
	float tr;
	int kesou;
};
patient a[200];
int main()
{
	int n,t=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].name>>a[i].tr>>a[i].kesou;
	}
	for(int i=0;i<n;i++){
		if(a[i].tr>=37.5&&a[i].kesou){
			cout<<a[i].name<<endl;
			t++;
		}
	}
	cout<<t;
	return 0;
}

