#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
stack<int> a;
int pushed[100001];
int main()
{
	int q;
	cin>>q;
	for(int cishu=1;cishu<=q;cishu++){
		int n,flag=1,top=0;
		cin>>n;
		memset(pushed,0,sizeof(pushed));
		for(int i=0;i<n;i++){
			cin>>pushed[i];
		}
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			if(!a.empty()&&a.top()!=x){
				do{
					a.push(pushed[top++]);
				}while(a.top()!=x&&top<n);
			}
			else if(a.empty()){
				do{
					a.push(pushed[top++]);
				}while(a.top()!=x&&top<n);
			}
			if(!a.empty()&&a.top()==x) a.pop();
			else flag=0;
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		while(!a.empty()){
			a.pop();
		}
	}
	return 0;
}
