#include<iostream>
#include<cstdio>
using namespace std;
long long a[20];
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	cin>>n;
	a[0]=1;a[1]=1;
	for(int i=2;i<n;i++){
		for(int j=0;j<i;j++){
			a[i]=a[i]+a[j]*a[i-j-1];
		}
	}
	cout<<a[n]<<endl;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}




