#include<iostream>
#include<cstdio>
using namespace std;
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
void qian(tree t){
    if(!t) return;
    cout<<t->v<<' ';
    qian(t->ch[0]);
    qian(t->ch[1]);
}
void zhong(tree t){
    if(!t) return;
    zhong(t->ch[0]);
    cout<<t->v<<' ';
    zhong(t->ch[1]);
}
void hou(tree t){
    if(!t) return;
    hou(t->ch[0]);
    hou(t->ch[1]);
    cout<<t->v<<' ';
}
int main()
{
    cin>>n;
    int a;
    while(n--){
        cin>>a;
        ins(rt,a);
    }
    qian(rt);
    putchar('\n');
    zhong(rt);
    putchar('\n');
    hou(rt);
    putchar('\n');
    return 0;
}