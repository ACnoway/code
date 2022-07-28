//֤α
#include <iostream>
#include <cstdio>
using namespace std;
int a[55];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int T=1;T<=t;++T){
		int now=1;
		for(int i=0;i<=53;++i) a[i]=0;
		string s;
		cin>>s;
		int n=s.size();
		for(int i=0;i<n;++i){
			if(s[i]=='E'){
				if(a[i]||a[(i+1)%n]){
					cout<<"NO"<<endl;
					break;
				}
				a[i]=a[(i+1)%n]=now++;
			}
			else{
				if(a[i]||a[(i+1)%n]){
					cout<<"NO"<<endl;
					break;
				}
				a[i]=a[(i+1)%n]=now++;
			}
		}
	}
	return 0;
}