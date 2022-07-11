//线段树开四倍数组！！！
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
namespace mode1{
    //单点修改，区间查询
    struct node{
        int l,r,sum;
    }t[10000001];
    int a[10000001];

    //i表示当前结点下标，2*i为左孩子，2*i+1为右孩子
    //l为当前结点的左端点，r为右端点
    //注意是给出的数组的左右下标
    inline void build(int i,int l,int r){
        t[i].l=l;t[i].r=r;
        if(l==r){
        //如果是叶子结点就赋值
        //叶子结点就是l和r不能再分下去的结点
            t[i].sum=a[l];
            return;
        }
        //二分思想，递归插结点
        int mid=(l+r)>>1;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        t[i].sum=t[i*2].sum+t[i*2+1].sum;
        //计算总和
    }

    //l和r是要查找的左右端点
    //区间查询
    inline int search(int i,int l,int r){
        //如果当前结点跟要查找的左右端点没交集的话就返回0
        if(t[i].r<l||t[i].l>r) return 0;
        //如果要查找的左右端点把当前结点完全包含了就返回当前结点的值
        if(t[i].l>=l&&t[i].r<=r) return t[i].sum;
        int s=0;

        //去看左孩子和右孩子跟要查找的有没有交集
        //因为线段树的定义是左孩子的左端点等于当前结点的左端点
        //右孩子的右端点等于当前结点的右端点
        //所以直接判断左孩子的右端点和右孩子的左端点即可
        if(t[i*2].r>=l) s+=search(i*2,l,r);
        //反之
        if(t[i*2+1].l<=r) s+=search(i*2+1,l,r);
        return s;
    }

    //给第dis个结点添加k
    //单点修改
    inline void add(int i,int dis,int k){
        if(t[i].l==t[i].r){
            //如果是叶子结点就找到了
            //肯定是可以找到的，因为对于dis
            //只要dis不超过n，就能找到
            //因为线段树到最后每个下标都会有一个结点
            t[i].sum+=k;
            return;
        }
        //如果dis在左孩子
        if(dis<=t[i*2].r) add(i*2,dis,k);
        else add(i*2+1,dis,k);//在右孩子
        t[i].sum=t[i*2].sum+t[i*2+1].sum;
        //因为孩子的值变化了，所以返回时要根据之前推出来的定理更新sum
        return;
    }
}

namespace mode2{
    //单点查询，区间修改
    struct node
    {
        int l,r,sum,num;
    }t[2000005];
    int a[500005];
    inline void build(int i,int l,int r){
        t[i].l=l;t[i].r=r;
        t[i].num=0;
        if(l==r){
            t[i].sum=a[l];
            return;
        }
        int mid=(l+r)>>1;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        t[i].sum=t[i*2].sum+t[i*2+1].sum;
    }
    inline int search(int i,int dis,int ans){
        ans+=t[i].num;
        if(t[i].l==t[i].r){
            return ans+t[i].sum;
        }
        if(dis<=t[i*2].r) return search(i*2,dis,ans);
        if(dis>=t[i*2+1].l) return search(i*2+1,dis,ans);
    }
    inline void add(int i,int l,int r,int k){
        if(t[i].l>=l&&t[i].r<=r){
            t[i].num+=k;
            return;
        }
        if(t[i*2].r>=l) add(i*2,l,r,k);
        if(t[i*2+1].l<=r) add(i*2+1,l,r,k);
    }
}
namespace mode3{
    //区间查询,区间加
    struct node
    {
        int lt;
        int l,r,sum;
    }t[400020];
    int a[100005];
    inline void build(int i,int l,int r){
        t[i].l=l;
        t[i].r=r;
        t[i].lt=0;
        if(l==r){
            t[i].sum=a[l];
            return;
        }
        int mid=(l+r)>>1;
        build(i<<1,l,mid);
        build(i<<1|1,mid+1,r);
        t[i].sum=t[i<<1].sum+t[i<<1|1].sum;
        return;
    }
    inline void pushdown(int i){
        if(t[i].lt){
            //传递lazytag
            t[i<<1].lt+=t[i].lt;
            t[i<<1|1].lt+=t[i].lt;
            //计算对子树的影响
            int mid=(t[i].l+t[i].r)>>1;
            t[i<<1].sum+=t[i].lt*(mid-t[i<<1].l+1);
            t[i<<1|1].sum+=t[i].lt*(t[i<<1|1].r-mid);
            t[i].lt=0;
        }
    }
    inline void add(int i,int l,int r,int k){
        if(t[i].l>=l&&t[i].r<=r){
            t[i].sum+=k*(t[i].r-t[i].l+1);
            t[i].lt+=k;
            return;
        }
        pushdown(i);
        if(t[i<<1].r>=l) add(i<<1,l,r,k);
        if(t[i<<1|1].l<=r) add(i<<1|1,l,r,k);
        t[i].sum=t[i<<1].sum+t[i<<1|1].sum;
        return;
    }
    inline int search(int i,int l,int r){
        if(t[i].l>=l&&t[i].r<=r) return t[i].sum;
        pushdown(i);
        int s=0;
        if(t[i<<1].r>=l) s+=search(i<<1,l,r);
        if(t[i<<1|1].l<=r) s+=search(i<<1|1,l,r);
        return s;
    }
}
namespace mode4{
    //区间查询，区间乘法
    int p;
    struct node
    {
        int plz,mlz;
        int l,r,sum;
    }t[400010];
    int a[100005];
    inline void build(int i,int l,int r){
        t[i].l=l;t[i].r=r;
        t[i].mlz=1;
        if(l==r){
            t[i].sum=a[l]%p;
            return;
        }
        int mid=(l+r)>>1;
        build(i<<1,l,mid);
        build(i<<1|1,mid+1,r);
        t[i].sum=(t[i<<1].sum+t[i<<1|1].sum)%p;
        return;
    }
    inline void pushdown(int i){
        if(t[i].mlz==1&&t[i].plz==0) return;
        int k1=t[i].mlz,k2=t[i].plz;
        t[i<<1].sum=(t[i<<1].sum*k1+k2*(t[i<<1].r-t[i<<1].l+1))%p;
        t[i<<1|1].sum=(t[i<<1|1].sum*k1+k2*(t[i<<1|1].r-t[i<<1|1].l+1))%p;
        t[i<<1].mlz=(t[i<<1].mlz*k1)%p;
        t[i<<1|1].mlz=(t[i<<1|1].mlz*k1)%p;
        t[i<<1].plz=(t[i<<1].plz*k1+k2)%p;
        t[i<<1|1].plz=(t[i<<1|1].plz*k1+k2)%p;
        t[i].mlz=1;
        t[i].plz=0;
        return;
    }
    inline void mul(int i,int l,int r,int k){
        if(t[i].r<l||t[i].l>r) return;
        if(t[i].l>=l&&t[i].r<=r){
            t[i].sum=(t[i].sum*k)%p;
            t[i].mlz=(t[i].mlz*k)%p;
            t[i].plz=(t[i].plz*k)%p;
            return;
        }
        pushdown(i);
        if(t[i<<1].r>=l) mul(i<<1,l,r,k);
        if(t[i<<1|1].l<=r) mul(i<<1|1,l,r,k);
        t[i].sum=(t[i<<1].sum+t[i<<1|1].sum)%p;
        return;
    }
    inline void add(int i,int l,int r,int k){
        if(t[i].r<l||t[i].l>r) return;
        if(t[i].l>=l&&t[i].r<=r){
            t[i].sum+=((t[i].r-t[i].l+1)*k)%p;
            t[i].plz=(t[i].plz+k)%p;
            return;
        }
        pushdown(i);
        if(t[i<<1].r>=l) add(i<<1,l,r,k);
        if(t[i<<1|1].l<=r) add(i<<1|1,l,r,k);
        t[i].sum=(t[i<<1].sum+t[i<<1|1].sum)%p;
        return;
    }
    inline int search(int i,int l,int r){
        if(t[i].r<l||t[i].l>r) return 0;
        if(t[i].l>=l&&t[i].r<=r) return t[i].sum;
        pushdown(i);
        int s=0;
        if(t[i<<1].r>=l) s+=search(i<<1,l,r);
        if(t[i<<1|1].l<=r) s+=search(i<<1|1,l,r);
        return s%p;
    }
}
using namespace mode4;
int n,m;
signed main()
{
    n=read();
    m=read();
    p=read();
    for(int i=1;i<=n;++i) a[i]=read();
    build(1,1,n);
    for(int i=1;i<=m;++i){
        int op,x,y;
        op=read();x=read();y=read();
        if(op==1){
            int k=read();
            mul(1,x,y,k);
        }
        else if(op==2){
            int k=read();
            add(1,x,y,k);
        }
        else{
            write(search(1,x,y));
            putchar('\n');
        }
    }
    return 0;
}