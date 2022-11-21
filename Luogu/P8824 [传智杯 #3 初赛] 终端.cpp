#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<string,bool> m;
string a[1003];
string op,name1,name2;
int n,cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	while(n--){
		cin>>op;
		if(op=="touch"){
			cin>>name1;
			if(!m[name1]){
				m[name1]=1;
				a[++cnt]=name1;
			}
		}
		else if(op=="rm"){
			cin>>name1;
			m[name1]=0;
		}
		else if(op=="ls"){
			for(int i=1;i<=cnt;++i){
				if(m[a[i]]) cout<<a[i]<<endl;
			}
		}
		else{
			cin>>name1>>name2;
			if(m[name1]&&!m[name2]){
				m[name1]=0;
				m[name2]=1;
				for(int i=1;i<=cnt;++i){
					if(a[i]==name1){
						a[i]=name2;
						break;
					}
				}
			}
		}
	}
	return 0;
}
