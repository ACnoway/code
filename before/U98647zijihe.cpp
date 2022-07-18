#include<iostream>
#include<cstdio>
#include<cmath>
typedef unsigned int UI;
using namespace std;
UI s[100000001];
int main()
{
	int t,a,b;
	UI c,temp=0;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a>>b>>c;
		UI abc=0;
		s[abc++]=1;
		for(int o=1;s[o]<=c;o++){
			long long ta=pow(a,o),tb=pow(b,o);
			if(ta<=tb){
				s[abc++]=ta; s[abc++]=tb;
			}
			else{
				s[abc++]=tb; s[abc++]=ta;
			}
		}
		if(s[abc-1]==c||s[abc-2]+1==c){
			cout<<"T"<<endl;
			continue;
		}
		UI first=0,last=0;
		while(1){
			while(temp<=c){
				temp+=s[last++];
			}
			if(temp>c){
				temp-=s[--last];
			}
			if(temp<=0){
				cout<<"F"<<endl;
				break;
			} 
			if(temp==c){
				cout<<"T"<<endl;
				break;
			}
			last=++first;temp=0;
		}
	}
	return 0;
}
