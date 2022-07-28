#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
string s[100005];
int main()
{
	int n;
	string t;
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>s[i];
	sort(s,s+n);
	cin>>t;
	for(int i=0;i<n;++i){
		if(s[i].find(t)==0){
			cout<<s[i]<<endl;
		}
	}
	return 0;
}