#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
int n;
string s;
typedef pair<int,string> pis;
map<pis,int> m;
bool operator <(pis x,pis y){
	return x.first<y.first||(x.first==y.first&&x.second<y.second);
}
int dfs(int x,string now){
	if(x==n) return 0;
	if(m.find((pis){x,now})!=m.end()) return m[(pis){x,now}];
	int mi=dfs(x+1,now+s[x])+1,tn=now.size();
	if(tn) mi=min(mi,dfs(x,"")+1);
	if(tn&&now==s.substr(x,tn)) mi=min(dfs(x+tn,now+now)+1,mi);
	return m[(pis){x,now}]=mi;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s;
	n=s.size();
	cout<<dfs(0,"")<<endl;
	return 0;
}
