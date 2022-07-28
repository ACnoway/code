#include<iostream>
using namespace std;
int main()
{
	int n,high;
	cin>>n;
	for(int i=0;i<n;i++){
		int score;
		cin>>score;
		if(score>=high) high=score;
	}
	cout<<high;
	return 0;
}


