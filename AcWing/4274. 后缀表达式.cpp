#include<iostream>
using namespace std;
struct node{
    string v;
    int fa,lc,rc;
    node(){fa=0;}
}t[30];
int n;
void work(int x){
    if(t[x].lc!=-1){
        cout<<'(';
        work(t[x].lc);
        cout<<')';
    }
    if(t[x].lc==-1&&t[x].rc!=-1) cout<<t[x].v;
    if(t[x].rc!=-1){
        cout<<'(';
        work(t[x].rc);
        cout<<')';
    }
    if(!(t[x].lc==-1&&t[x].rc!=-1)) cout<<t[x].v;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>t[i].v>>t[i].lc>>t[i].rc;
        if(t[i].lc!=-1) t[t[i].lc].fa=i;
        if(t[i].rc!=-1) t[t[i].rc].fa=i;
    }
    int root;
    for(int i=1;i<=n;++i){
        if(t[i].fa==0){
            root=i;
            break;
        }
    }
    cout<<'(';
    work(root);
    cout<<')';
    return 0;
}