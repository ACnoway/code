#include<iostream>
using namespace std;
int cute[101],cute1[101];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>cute[i];
	}
	for(int i=0;i<n;i++){
		cute1[i]=0;
	}
	cout<<"0";
	for(int i=1;i<n;i++){
		for(int x=0;x<i;x++){
			if(cute[i]>cute[x]) cute1[i]+=1;
		}
		cout<<" "<<cute1[i];
	}
	return 0;
}

