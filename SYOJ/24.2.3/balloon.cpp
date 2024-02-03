#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
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
const int N=100005;
int k,n;
bool a[N+N];
char o[N],kk[3]={'L','R','F'};
int main()
{
	freopen("balloon.in","r",stdin);
	freopen("balloon.out","w",stdout);
    k=read();
    n=read();
    for(int i=1;i<=k;++i){
    	int x=read();
    	a[x+N]=1;
	}
	for(int i=1;i<=n;++i){
		char op=getchar();
		while(op!='L'&&op!='R'&&op!='F') op=getchar();
		o[i]=op;
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		char yuan=o[i];
		for(int kkk=0;kkk<3;++kkk){
			int x=0,cnt=0;
			o[i]=kk[kkk];
			for(int j=1;j<=n;++j){
				if(o[j]=='L'){
					--x;
				}
				else if(o[j]=='R'){
					++x;
				}
				else{
					cnt+=a[x+N];
				}
			}
			ans=max(ans,cnt);
		}
		o[i]=yuan;
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
}
