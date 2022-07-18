#include<iostream>
using namespace std;
int main()
{
	int h,k,x;
	char a;
	cin>>h>>k>>a>>x;
	if(x==1){
		for(int i=0;i<h;i++){
			for(int y=0;y<k;y++){
				cout<<a;
			}
			if(i<=h-2) cout<<endl;
		} 
	}
	else{
		for(int y=0;y<k;y++){
			cout<<a;
		}
		cout<<endl;
		for(int i=1;i<h-1;i++){
			for(int y=0;y<k;y++){
				if(y==0||y==k-1) cout<<a;
				else cout<<" ";
			}
			if(i<=h-2) cout<<endl;
		}
		for(int y=0;y<k;y++){
			cout<<a;
		}
	}
	return 0;
}

