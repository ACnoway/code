#include<iostream>
using namespace std;
int main()
{
	int s[7]={0},buy[7]={0},t[7]={0},a=0,b;
	cin>>b;
	for(int i=0;i<7;i++) cin>>s[i];
	for(int i=0;i<b;i++){
		a=0; 
		for(int x=0;x<7;x++) cin>>buy[x];
		for(int x=0;x<7;x++){
			for(int y=0;y<7;y++){
				if(s[x]==buy[y]) a++;
			}
		}
		for(int x=1;x<=7;x++){
			if(a==x) t[x-1]++;
		}
	}
	for(int i=6;i>=0;i--) cout<<t[i]<<" ";
	return 0;
}

