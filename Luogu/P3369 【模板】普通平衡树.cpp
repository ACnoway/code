#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl
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
const int inf =1<<27;
inline int Rand(){
    static unsigned long long r=2333;
    return (r*=233333)%=2147483647;
}
struct node{
    node* ch[2];
    int val,siz,cnt,pri;
    node(int v=0): val(v){siz=cnt=1;pri=Rand();ch[0]=ch[1]=nullptr;}
    int cmp(int x){
        if(x==val) return -1;
        return x>=val;
    }
    void update(){
        siz=cnt;
        if(ch[0]) siz+=ch[0]->siz;
        if(ch[1]) siz+=ch[1]->siz;
    }
};
typedef node* tree;
tree rt=nullptr;
int n;
inline void rotate(tree &p,int d){
    tree k=p->ch[d^1];
    p->ch[d^1]=k->ch[d];
    k->ch[d]=p;
    p->update(); k->update();
    p=k;
}
void ins(tree &p,int x){
    if(!p){p=new node(x);return;}
    if(x==p->val){++p->siz;++p->cnt;return;}
    int d=p->cmp(x);
    ins(p->ch[d],x);
    if(p->ch[d]->pri<p->pri) rotate(p,d^1);
    p->update();
}
void del(tree &p,int x){
    if(!p) return;
    if(x==p->val){
        if(p->cnt>1){
            --p->siz;
            --p->cnt;
            return;
        }
        if(!p->ch[0]){
            tree k=p;
            p=p->ch[1];
            delete k;
        }
        else if(!p->ch[1]){
            tree k=p;
            p=p->ch[0];
            delete k;
        }
        else{
            int dd=(p->ch[0]->pri<p->ch[1]->pri);
            rotate(p,dd); del(p->ch[dd],x);
        }
    }
    else if(x<p->val) del(p->ch[0],x);
    else del(p->ch[1],x);
    if(p) p->update();
}
int rk(tree p,int x){
    if(!p) return 1;
    int ss=(p->ch[0]?p->ch[0]->siz:0);
    if(x==p->val) return ss+1;
    else if(x<p->val) return rk(p->ch[0],x);
    else return ss+p->cnt+rk(p->ch[1],x);
}
int kth(tree p,int k){
    if(!p) return -inf;
    int ss=(p->ch[0]?p->ch[0]->siz:0);
    if(k<=ss) return kth(p->ch[0],k);
    else if(k<=ss+p->cnt) return p->val;
    else return kth(p->ch[1],k-p->cnt-ss);
}
int pre(tree p,int x){
    if(!p) return -inf;
    if(p->val>=x) return pre(p->ch[0],x);
    else return max(p->val,pre(p->ch[1],x));
}
int nxt(tree p,int x){
    if(!p) return inf;
    if(p->val<=x) return nxt(p->ch[1],x);
    else return min(p->val,nxt(p->ch[0],x));
}
int main()
{
    n=read();
    while(n--){
        int op=read(),x=read();
        if(op==1){
            ins(rt,x);
        }
        else if(op==2){
            del(rt,x);
        }
        else if(op==3){
            printf("%d\n",rk(rt,x));
        }
        else if(op==4){
            printf("%d\n",kth(rt,x));
        }
        else if(op==5){
            printf("%d\n",pre(rt,x));
        }
        else{
            printf("%d\n",nxt(rt,x));
        }
    }
    return 0;
}