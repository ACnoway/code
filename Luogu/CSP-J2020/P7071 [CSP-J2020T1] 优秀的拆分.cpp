#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int num[1000];
int main()
{
	int n,flag=0,nums=0;
	cin>>n;
    if(n&1){
        cout<<"-1"<<endl;
        return 0;
    }
	for(int i=(int)floor(log2(n));n>0&&i>0;i--){
		int temp=pow(2,i);
		if(n>=temp){
			cout<<temp<<' ';
			n-=temp;
		}
	}
	return 0;
}