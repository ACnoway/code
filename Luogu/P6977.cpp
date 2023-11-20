#include<bits/stdc++.h>
using namespace std;
queue<int,list<int> >q[20];//把queue的底层容器从deque换成list,更快 
int n,k,sum;
int main() {
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int m;
		cin>>m;
		for(int j=1;j<=m;j++){
			int x;
			cin>>x;
			q[i].push(x);
		}
	}
	while(k){//选k道题 
		for(int i=1;i<=n;i++){
			if(k==0) break;
			if(q[i].empty()) sum+=50,k--;
			else if(q[i].front()<sum) q[i].pop();
			else sum+=q[i].front(),q[i].pop(),k--;
		}
	}
	cout<<sum;
	return 0;
} 

