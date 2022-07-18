#include<iostream>
using namespace std;
int a[101]={0};
int main(){
	int n,add=0,flag=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int he=0;he<n;he++){
		for(int n1=0;n1<n;n1++){
			for(int n2=0;n2<n;n2++){
				if(n2==he||n1==he||n1==n2) continue;
				if(a[he]==a[n1]+a[n2]){
					add++;
					flag=1;
					break;
				}
			}
			if(flag==1){
				flag=0;
				break;
			}
		}
	}
	cout<<add;
	return 0;
}
