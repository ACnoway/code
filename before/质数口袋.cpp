#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
int s[1000001];
int main()
{
	int l,flag=0,c=0,add=0,a;
	cin>>l;
	a=2;
	while(add<=l){
		flag=0; 
		for(int x=1;x<=a;x++){
			if(a%x==0) flag++;
		}
		if(flag==2){
			add+=a;
			s[c++]=a;
		}
		a++;
	}
	for(int i=0;i<c-1;i++){
		cout<<s[i]<<endl;
	}
	cout<<c-1;
	return 0;
}

