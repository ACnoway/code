#include<iostream>
using namespace std;
int main()
{
	int n,big,small;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(a>=big) big=a;
		if(a<=small) small=a;
	} 
	int mid=big-small;
	cout<<mid;
	return 0;
}


