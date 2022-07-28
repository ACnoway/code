#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(false); 
    int n;
    cin>>n;
    n=(int)pow(2,n);
    for(int i=1;i<=n;i++){
		for(int o=n-i;o>0;o--){
			cout<<"0 ";
		}
		if(i%2==0){
			for(int o=1;o<=i;o++){
				cout<<"1 ";
			}
		}
		else{
			bool flag=false;
			for(int o=1;o<=i;o++){
				if(flag){
					flag=false; cout<<"0 ";
				}
				else{
					flag=true; cout<<"1 ";
				}
			}
		}
		cout<<endl;
	}
    return 0;
}
