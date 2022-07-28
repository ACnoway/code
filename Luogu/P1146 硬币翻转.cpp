#include <iostream>
#include <cstdio>
using namespace std;
string s;
int n;
int main()
{
	cin>>n;
	for(int i=0;i<n;++i) s+='0';
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)
			if(j!=i) s[j]=(s[j]=='0'?'1':'0');
		cout<<s<<endl;
	}
	return 0;
}