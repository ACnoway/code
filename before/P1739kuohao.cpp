#include<iostream>
using namespace std;
int main()
{
	string a;
	cin>>a;
	int t=0;
	for(int i=0;i<a.size();i++){
		if(a[i]=='(') t++;
		if(a[i]==')') t--;
		if(t<0){
			cout<<"NO"; return 0;
		}
	}
	if(!t) cout<<"YES";
	else cout<<"NO";
	return 0;
}
