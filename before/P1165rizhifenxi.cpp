#include<iostream>
#include<stack>
using namespace std;
stack<int> a;
int maxx[200001];
int main()
{
	//freopen("P1165.txt","w",stdout);
	int n,times=1;
	cin>>n;
	for(int i=0;i<n;i++){
		int cz;
		cin>>cz;
		switch(cz){
			case 0:{
				int x;
				cin>>x;
				if(maxx[times-1]<=x) maxx[times++]=x;
				//cout<<maxx[times-1]<<endl;
				a.push(x);
				break;
			}
			case 1:{
				if(maxx[times-1]==a.top()) times--;
				a.pop();
				break;
			}
			case 2:{
				cout<<maxx[times-1]<<endl;
				break;
			}
		}
	}
	return 0;
}
