#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int read(){
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
const int inf=1e9+7;
const int maxn=500010;
int n,rt,tot;
int rnd[maxn],val[maxn],ch[maxn][2];
int siz[maxn],cnt[maxn];
void update(int p){siz[p]=siz[ch[p][0]]+siz[ch[p][1]]+cnt[p];}
void rotate(int &p,int d){
	int k=ch[p][d^1];
	ch[p][d^1]=ch[k][d];
	ch[k][d]=p;
	update(p);update(k);
	p=k;
}
void ins(int &p,int x){
	if(!p){
		p=++tot;
		val[p]=x;
		rnd[p]=rand();
		siz[p]=cnt[p]=1;
		return;
	}
	if(val[p]==x){siz[p]++;cnt[p]++;return;}
	int d=x<val[p]?0:1;
	ins(ch[p][d],x);
	if(rnd[ch[p][d]]<rnd[p]) rotate(p,d^1);
	update(p);
}
void del(int &p,int x){
	if(!p) return;
	if(val[p]==x){
		if(cnt[p]>1){siz[p]--;cnt[p]--;return;}
		else{
			if(!ch[p][1]) p=ch[p][0];
			else if(!ch[p][0]) p=ch[p][1];
			else{
				int dd=rnd[ch[p][0]]<rnd[ch[p][1]]?1:0;
				rotate(p,dd);del(ch[p][dd],x);
			}
		}
	}
	else if(x<val[p]) del(ch[p][0],x);
	else del(ch[p][1],x);
	if(p) update(p);
}
int rnk(int p,int x){
	int ss=siz[ch[p][0]];
	if(x<val[p]) return rnk(ch[p][0],x);
	else if(x==val[p]) return ss+1;
	else return ss+cnt[p]+rnk(ch[p][1],x);
}
int kth(int p,int k){
	int ss=siz[ch[p][0]];
	if(k<=ss) return kth(ch[p][0],k);
	else if(k<=ss+cnt[p]) return val[p];
	else return kth(ch[p][1],k-ss-cnt[p]);
}
int pre(int p,int x){
	if(!p) return -inf;
	if(x<=val[p]) return pre(ch[p][0],x);
	else return max(val[p],pre(ch[p][1],x));
}
int nxt(int p,int x){
	if(!p) return inf;
	if(x>=val[p]) return nxt(ch[p][1],x);
	else return min(val[p],nxt(ch[p][0],x));
}
int main()
{
	n=read();
	while(n--){
		int op=read(),x=read();
		if(op==1) ins(rt,x);
		else if(op==2) del(rt,x);
		else if(op==3) printf("%d\n",rnk(rt,x));
		else if(op==4) printf("%d\n",kth(rt,x));
		else if(op==5) printf("%d\n",pre(rt,x));
		else if(op==6) printf("%d\n",nxt(rt,x));
	}
	return 0;
}