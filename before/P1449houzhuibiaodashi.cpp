#include<iostream>
#include<stack>
using namespace std;
int a[1001];
string s;
int main()
{
	cin>>s;
	int top=0;
	for(int i=0;i<s.size()&&s[i]!='@';i++){
		switch(s[i]){
			case '+':{
				a[--top]+=a[top+1];
				break;
			}
			case '-':{
				a[--top]-=a[top+1];
				break;
			}
			case '*':{
				a[--top]*=a[top+1];
				break;
			}
			case '/':{
				a[--top]/=a[top+1];
				break;
			}
			default:{
				int x=0;
				while(s[i]!='.') x=x*10+s[i++]-'0';
				a[++top]=x;
				break;
			}
		}
	}
	cout<<a[top];
	return 0;
}
