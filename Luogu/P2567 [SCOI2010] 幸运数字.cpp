#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#define int unsigned long long
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3ull)+(x<<1ull)+(c^48);
		c=getchar();
	}
	return x*f;
}
int a,b,ans;
unordered_map<int,bool> m;
signed main()
{
	a=read();
	b=read();
	int tmp,tt;
	bool flag;
	if(a>b) swap(a,b);
	for(int i=1;i<a;++i){
		tmp=i;
		flag=0;
		if(m[i]) flag=1;
		else{
			flag=1;
			while(tmp){
				tt=tmp%10;
				if(tt!=6&&tt!=8){
					//判断组成
					flag=0;
					break;
				}
				tmp/=10;
			}
			if(flag) m[i]=1;
		}
		if(flag){
			for(int j=i+i;j<=b;j+=i) m[j]=1;
		}
	}
	for(int i=a;i<=b;++i){
		tmp=i;
		flag=0;
		if(m[i]) flag=1;
		else{
			flag=1;
			while(tmp){
				tt=tmp%10;
				if(tt!=6&&tt!=8){
					//判断组成
					flag=0;
					break;
				}
				tmp/=10;
			}
			if(flag) m[i]=1;
		}
		if(flag){
			++ans;
			for(int j=i+i;j<=b;j+=i) m[j]=1;
		}
	}
	printf("%Ld\n",ans);
	return 0;
}
