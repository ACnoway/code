#include<iostream>
#include<set>
using namespace std;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	set<int> s;
	int l,m;
	cin>>l>>m; 
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		for(int x=u;x<=v;x++){
			s.insert(x);
		}
	}
	cout<<l-s.size()+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

