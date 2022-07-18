#include<iostream>
#include<cstdio>
#include<set>
#include<queue>
using namespace std;
queue<int> rj;
set<int> wd;
int m,n,t=0;
inline void jiaru(int a){
	if(rj.size()==m){
		int temp=rj.front();
		wd.erase(temp);
		rj.pop();
		rj.push(a);
		wd.insert(a);
	}
	else{
		wd.insert(a);
		rj.push(a);
	}
}
int main()
{
	cin>>m>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(wd.count(x)){
			continue;
		}
		else{
			t++;
			jiaru(x);
		}
	} 
	cout<<t;
	return 0;
}

