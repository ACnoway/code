#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int n,y=0,f=0;
	cin>>n;
	for(int cishu=1;cishu<=n;cishu++){
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++){
			if(s[i]=='(') y++;
			else if(s[i]==')'&&(s[i-1]=='('||s[i-1]==']')) y--;
			else if(s[i]=='[') f++;
			else if(s[i]==']'&&(s[i-1]==')'||s[i-1]=='[')) f--;
		}
		bool flag;
		if(y==0&&f==0) flag=true;
		else flag=false;
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		y=0; f=0;
	}
	return 0;
}
