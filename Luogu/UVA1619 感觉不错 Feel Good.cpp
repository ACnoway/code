#include <iostream>
#include <cstdio>
#define int long long
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
void write(int x){
	if(x<0){x=-x;putchar('-');}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int a[100005],l[100005],r[100005],s[100005],p[100005];
int n,t,top;
signed main()
{
	while(scanf("%d",&n)!=EOF){
		int ans=0,z=1,y=1;
		if(t++) putchar('\n');
		for(int i=1;i<=n;++i){
			a[i]=read();
			p[i]=p[i-1]+a[i];
		}
		//枚举每一个元素ai作为一个序列的最小值，找出这个序列的左右端点（也就是左右第一个比ai小的）
		//找左边第一个比ai小的
		for(int i=n;i>0;--i){
			while(top&&a[i]<a[s[top]]) l[s[top--]]=i+1;
			s[++top]=i;
		}
		while(top) l[s[top--]]=1;
		for(int i=1;i<=n;++i){
			while(top&&a[i]<a[s[top]]) r[s[top--]]=i-1;
			s[++top]=i;
		}
		while(top) r[s[top--]]=n;
		int temp=0;
		for(int i=1;i<=n;++i){
			temp=a[i]*(p[r[i]]-p[l[i]-1]);
			if(temp>ans||(temp==ans&&(r[i]-l[i]<y-z||r[i]-l[i]==y-z&&l[i]<z))){
				ans=temp;
				z=l[i];y=r[i];
			}
		}
		printf("%lld\n%lld %lld\n",ans,z,y);
	}
	return 0;
}