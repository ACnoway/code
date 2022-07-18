#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
int main()
{
	int n,a=1;
	cin>>n;
	int b=n;
	for(int i=1;i<=n;i++){
			for(int y=b;y>0;y--){
				printf("%02d",a++);
			}
			b--;
			if(i<=n-1) cout<<endl;
		}
	return 0;
}

