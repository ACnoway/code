#include<iostream>
using namespace std;
const int N=100005;
int m;
int e[N],ne[N],head,idx;
void init(){
    head=-1;
    idx=0;
}
void ins(int x){
    e[idx]=x;
    ne[idx]=head;
    head=idx++;
}
void ins(int k,int x){
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx++;
}
void del(int k){
    ne[k]=ne[ne[k]];
}
int main()
{
    cin>>m;
    char c;
    int k,x;
    init();
    while(m--){
        cin>>c;
        if(c=='H'){
            cin>>x;
            ins(x);
        }
        else if(c=='D'){
            cin>>k;
            if(k==0) head=ne[head];
            else del(k-1);
        }
        else{
            cin>>k>>x;
            ins(k-1,x);
        }
    }
    for(int i=head;i!=-1;i=ne[i]) cout<<e[i]<<' ';
    
    return 0;
}