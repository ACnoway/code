#include<bits/stdc++.h>
#define Misaka namespace  
#define Mikoto std 
#define ull unsigned long long 
using Misaka Mikoto;
namespace READ
{
	ull Read()
	{
		char ch=getchar();
		ull s=0;
		while(ch<'0'||ch>'9') ch=getchar();
		while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
		return s;
	}
	ull tp[10005];
	int l,r;
	ull g1,g2;
	void init(int &n)
	{
		int i,k;
		n=Read(),k=Read(),l=1;
		for(i=1;i<=k;i++)
			tp[i]=Read();
	}
	ull read()
	{
		if(l>r)
			l=Read(),r=Read(),g1=Read(),g2=Read();
		return tp[l++]*g1+g2;
	}
}
long long a[10004];
int main()
{
	int n;
   	READ::init(n);
    for(int i=0;i<n;++i) a[i]=READ::read();
    unsigned long long ans=0,tmp=0;
    for(int l=0;l<n;++l){
        tmp=0;
        for(int i=l;i<n;++i){
            tmp|=a[i];
            ans+=tmp;
        }
    }
    cout<<ans<<endl;
}
