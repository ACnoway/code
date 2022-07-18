#include<iostream>
#include<vector>
using namespace std;
int ti[81]={0};
int main()
{
	int a,b,c,t=0,m;
	vector<int> most;
	cin>>a>>b>>c;
	for(int i=1;i<=a;i++){
		for(int o=1;o<=b;o++){
			for(int p=1;p<=c;p++){
				ti[i+o+p]++;
			}
		}
	}
	for(int i=0;i<=80;i++){
		if(ti[i]>t){
			t=ti[i];
			most.insert(most.begin(),i);
		}
	}
	cout<<*most.begin();
	return 0;
}

