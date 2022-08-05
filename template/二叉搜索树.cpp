#include<iostream>
#include<cstdio>
using namespace std;
const int INF=2147483647;
struct node
{
    node* ch[2];
    int v,siz,cnt;
    node(int x):v(x){siz=cnt=1;ch[0]=ch[1]=nullptr;}
    int cmp(int x){
        if(x==v) return -1;
        return x<v?0:1;
    }
};
typedef node* tree;
tree rt=nullptr;
int n;
void ins(tree &p,int x){
    if(!p){p=new node(x);return;}
    if(x==p->v){++p->siz;++p->cnt;return;}
    int d=p->cmp(x);
    ins(p->ch[d],x);
    ++p->siz;
}
int rk(tree t,int x){
    if(!t) return 0;
    int ss=(t->ch[0]?t->ch[0]->siz:0);
    if(x==t->v) return ss+1;
    else if(x<t->v) return rk(t->ch[0],x);
    else return ss+t->cnt+rk(t->ch[1],x);
}
int kth(tree t,int k){
    if(!t) return 0;
    int ss=(t->ch[0]?t->ch[0]->siz:0);
    if(k<=ss) return kth(t->ch[0],k);
    else if(k<=ss+t->cnt) return t->v;
    else return kth(t->ch[1],k-ss-t->cnt);
}
int pre(tree t,int x){
    if(!t) return -INF;
    if(t->v>=x) return pre(t->ch[0],x);
    else return max(t->v,pre(t->ch[1],x));
}
int nxt(tree t,int x){
    if(!t) return INF;
    if(t->v<=x) return nxt(t->ch[1],x);
    else return min(t->v,nxt(t->ch[0],x));
}
int main()
{
    cin>>n;
    int op,a;
    while(n--){
        cin>>op>>a;
        switch (op)
        {
        case 1:
            cout<<rk(rt,a)+1<<endl;
            break;
        case 2:
            cout<<kth(rt,a)<<endl;
            break;
        case 3:
            cout<<pre(rt,a)<<endl;
            break;
        case 4:
            cout<<nxt(rt,a)<<endl;
            break;
        case 5:
            ins(rt,a);
            break;
        }
    }
    return 0;
}