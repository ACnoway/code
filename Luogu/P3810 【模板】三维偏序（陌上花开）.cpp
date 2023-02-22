#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int maxn=200005;
struct node{
    int a,b,c,cnt,ans;
}s1[maxn],s2[maxn];
int n,m,k,mx,top,su[maxn];
int c[maxn];
bool cmp1(node x,node y)
{
	if(x.a==y.a)
	{
		if(x.b==y.b)return x.c<y.c;
		else return x.b<y.b;
	}
	else return x.a<y.a;
}//第一维排序

bool cmp2(node x,node y)
{
	if(x.b==y.b)
	return x.c<y.c;
	else return x.b<y.b;
}//第二维排序
inline int lowbit(int x){
    return x&(-x);
}
void add(int x,int y){
    while(x<=mx){
        c[x]+=y;
        x+=lowbit(x);
    }
}
inline int query(int x){
    int sum=0;
    while(x){
        sum+=c[x];
        x-=lowbit(x);
    }
    return sum;
}
void cdq(int l,int r){
    if(l==r) return;
    int mid=(l+r)>>1;
    cdq(l,mid);
    cdq(mid+1,r);
    sort(s2+l,s2+mid+1,cmp2);
    sort(s2+mid+1,s2+r+1,cmp2);
    int i,j=l;
    for(i=mid+1;i<=r;++i){
        while(s2[i].b>=s2[j].b&&j<=mid){
            add(s2[j].c,s2[j].cnt);
            ++j;
        }
        s2[i].ans+=query(s2[i].c);
    }//类似于归并的操作
    //清空树状数组
    for(i=l;i<j;++i) add(s2[i].c,-s2[i].cnt);
}
int main()
{
    n=read();
    k=read();
    mx=k;//树状数组的区间
    for(int i=1;i<=n;++i){
        s1[i].a=read();
        s1[i].b=read();
        s1[i].c=read();
    }
    sort(s1+1,s1+1+n,cmp1);
    for(int i=1;i<=n;++i){//去重
        top++;
        if(s1[i].a!=s1[i+1].a||s1[i].b!=s1[i+1].b||s1[i].c!=s1[i+1].c){
            m++;
            s2[m].a=s1[i].a;
            s2[m].b=s1[i].b;
            s2[m].c=s1[i].c;
            s2[m].cnt=top;
            top=0;
        }
    }
    cdq(1,m);
    for(int i=1;i<=m;++i)
        su[s2[i].ans+s2[i].cnt-1]+=s2[i].cnt;
    for(int i=0;i<n;++i) write(su[i]),putchar('\n');
    return 0;
}