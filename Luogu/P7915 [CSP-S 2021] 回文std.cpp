#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
#define N 1000010
using namespace std;
int n;
int v[N];
char ans[N],cur[N];
struct sta{
    int s[N],l,r;
    int L(){return s[l];}
    int R(){return s[r-1];}
    void push(int x){s[r++]=x;}
    void pL(){l++;}
    void pR(){r--;}
    void clear(){l=r=0;}
    bool empty(){return r==l;}
    int size(){return r-l;}
}a,b;
int see(int l,int r,int val){
    for(int i=l;i<=r;++i){
        if(v[i]==val) return i;
    }
    return -1;
}
void check(){
    int now=2;
    while(1){
        if(a.empty()&&b.empty()){
            break;
        }
        else if(b.empty()){
            if(a.L()!=a.R()){
                cur[1]='Z';
                return;
            }
            cur[now]=cur[2*n-now+1]='L';
            a.pL();
            a.pR();
        }
        else if(a.empty()){
            if(b.L()!=b.R()){
                cur[1]='Z';
                return;
            }
            cur[now]=cur[2*n-now+1]='R';
            b.pL();
            b.pR();
        }
        else{
            if(a.R()==a.L()&&a.size()>1){
                cur[now]=cur[2*n-now+1]='L';
                a.pL();
                a.pR();
            }
            else if(a.R()==b.L()){
                cur[now]='L';
                cur[2*n-now+1]='R';
                b.pL();
                a.pR();
            }
            else if(b.R()==a.L()){
                cur[now]='R';
                cur[2*n-now+1]='L';
                a.pL();
                b.pR();
            }
            else if(b.R()==b.L()&&b.size()>1){
                cur[now]='R';
                cur[2*n-now+1]='R';
                b.pL();
                b.pR();
            }
            else{
                cur[1]='Z';
                return;
            }
        }
        now++;
    }
}
bool pan(){
    int id=1;
    while(id<=2*n&&cur[id]==ans[id]) id++;
    return id<=2*n&&cur[id]<ans[id];
}
int main()
{
    int t;
    cin>>t;
    int pos;
    while(t--){
        ans[1]='Y';
        cin>>n;
        for(int i=1;i<=2*n;++i) cin>>v[i];
        a.clear();
        b.clear();
        pos=see(2,2*n,v[1]);
        for(int i=pos-1;i>=2;--i) a.push(v[i]);
        for(int i=pos+1;i<=2*n;++i) b.push(v[i]);
        cur[1]='L';
        cur[2*n]='L';
        check();
        if(pan()){
            for(int i=1;i<=2*n;++i) ans[i]=cur[i];
        }
        a.clear();
        b.clear();
        pos=see(1,2*n-1,v[2*n]);
        for(int i=pos-1;i>=1;--i) a.push(v[i]);
        for(int i=pos+1;i<=2*n-1;++i) b.push(v[i]);
        cur[1]='R';
        cur[2*n]='L';
        check();
        if(pan()){
            for(int i=1;i<=2*n;++i) ans[i]=cur[i];
        }
        if(ans[1]=='Y'){
            cout<<"-1"<<endl;
        }
        else{
            for(int i=1;i<=2*n;++i) cout<<ans[i];
            cout<<endl;
        }
    }
    return 0;
}
