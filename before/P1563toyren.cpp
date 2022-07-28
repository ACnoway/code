#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
string a[100001];
map<string,int> toy;
int now=1,cz[3][100001];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int tt;
		cin>>tt>>a[i];
		toy[a[i]]=tt;
	}
	for(int i=1;i<=m;i++){
		cin>>cz[1][i]>>cz[0][i];
	}
	for(int i=1;i<=m;i++){
		if(cz[1][i]==1){
			if(toy[a[now]]==0){
				if(now+cz[0][i]>n) now-=n;
				now+=cz[0][i];
			}
			else if(toy[a[now]]==1){
				if(now-cz[0][i]<1) now+=n;
				now-=cz[0][i];
			}
		}
		else if(cz[1][i]==0){
			if(toy[a[now]]==1){
				if(now+cz[0][i]>n) now-=n;
				now+=cz[0][i];
			}
			else if(toy[a[now]]==0){
				if(now-cz[0][i]<1) now+=n;
				now-=cz[0][i];
			}
		}
	}
	cout<<a[now];
	return 0;
}

