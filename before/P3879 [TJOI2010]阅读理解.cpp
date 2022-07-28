#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
string a[1001][5001];
int b[1001];
int main()
{
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b[i];
		for(int o=0;o<b[i];o++){
			cin>>a[i][o];
		}
	}
	cin>>m;
	for(int i=0;i<m;i++){
		string temp;
		cin>>temp;
		for(int o=0;o<n;o++){
			for(int p=0;p<b[o];p++){
				if(a[o][p]==temp){
					cout<<o+1;
					if(o<n-1) cout<<' ';
					break;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
