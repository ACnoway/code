#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#define int long long
using namespace std;
const int N=300005;
int n,ans;
string s;
bool f[N];
vector<int> wen,yi;
void dfs(int x){
	if(x>=wen.size()){
		int tiao=1,tmp;
		for(int i=1;i<yi.size();++i){
			if(!f[yi[i]]){
				++tiao;
				continue;
			}
			tmp=yi[i]-yi[i-tiao]-1;
			ans+=tmp*tmp;
			tiao=1;
		}
		return;
	}
	dfs(x+1);
	f[wen[x]]=1;
	dfs(x+1);
}
signed main()
{
	cin>>n>>s;
	s='1'+s+'1';
	for(int i=0;i<=n+1;++i){
		if(s[i]=='1') yi.emplace_back(i),f[i]=1;
		else if(s[i]=='?'){
			yi.emplace_back(i);
			wen.emplace_back(i);
		}
	}
	if(wen.empty()){
		for(int i=1;i<yi.size();++i){
			ans+=(yi[i]-yi[i-1]-1)*(yi[i]-yi[i-1]-1);
		}
		cout<<ans<<endl;
		return 0;
	}
	dfs(0);
	printf("%.4lf\n",(double)ans/(1<<wen.size()));
	return 0;
}
