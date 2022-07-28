#include<iostream>
#include<set>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100001];
set<int> b;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	int last=a[0],maxx=0;
	b.insert(b.begin(),last);
	for(int i=1;i<n;i++){
		if(a[i]==last+1){
			last=a[i];
			b.insert(b.begin(),a[i]);
			
		}
		else{
			if(b.size()>maxx) maxx=b.size();
			b.clear(); last=a[i];b.insert(b.begin(),last);
		}
	}
	cout<<maxx;
    return 0;
}
