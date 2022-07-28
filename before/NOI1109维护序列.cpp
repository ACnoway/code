#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
vector<int> a(1001);
int out[1001],ti=0;
void cz(int czf,int i){
	i--;
	switch(czf){
		case 1:{
			out[ti++]=a[i];
			break;
		}
		case 2:{
			int v;
			cin>>v;
			a.insert(a.begin()+i,v);
			break;
		}
		case 3:{
			a.erase(a.begin()+i);
			break;
		}
	}
}
int main()
{
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		a.insert(a.begin()+i,temp);
	}
	cin>>m;
	for(int i=0;i<m;i++){
		int temp,t;
		cin>>temp>>t;
		cz(temp,t);
	}
	for(int i=0;i<ti;i++){
		cout<<out[i]<<endl;
	}
	return 0;
}
