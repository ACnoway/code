#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=100005,mod=1000000007;
int n,m;
int p[N],dian[N],bian[N];
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
int find(int x){
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
signed main()
{
	n=read(); m=read();
	//���鼯Ԥ���� 
	for(int i=0;i<=n;++i) p[i]=i,dian[i]=1;
	for(int i=0;i<m;++i){
		int u=read(),v=read();
		u=find(u),v=find(v);
		//�ϲ� 
		if(u==v) ++bian[u];
		else{
			p[u]=v;
			dian[v]+=dian[u];
			dian[u]=0;
			bian[v]+=bian[u]+1;
		}
	}
	int ans=1;
	for(int i=1;i<=n;++i){
		//��ÿ����ͨ��ķ�����
		//����ͨ���ڱ���С�ڡ����ڡ����ڵ���
		//��������� 
		if(p[i]!=i) continue;
		if(bian[i]<dian[i]) ans*=dian[i],ans%=mod;
		else if(bian[i]==dian[i]) ans<<=1,ans%=mod;
		else ans=0;
	}
	cout<<ans<<endl;
	return 0;
}
