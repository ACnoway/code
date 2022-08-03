#include<iostream>
#include<queue>
using namespace std;
struct node{
    int lc,rc,v;
}t[100];
const int INF=2147483647;
int a[50];
int n,cnt;
int build(int l,int r){
    if(l>=r) return -1;
    int mi=INF,mp;
    for(int i=l;i<r;++i){
        if(a[i]<mi){
            mi=a[i];mp=i;
        }
    }
    int root=cnt;
    t[cnt++]=(node){build(l,mp),build(mp+1,r),mi};
    return root;
}
void bfs(){
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        if(t[now].lc!=-1) q.push(t[now].lc);
        if(t[now].rc!=-1) q.push(t[now].rc);
        cout<<t[now].v<<' ';
    }
    return;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i];
    build(0,n);
    bfs();
    return 0;
}