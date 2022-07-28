#include<iostream>
#include<cstdio>
#include<stack>
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
const int N = 1000005;
int n,q,ck,t,cnt;
int a[N],flag[N],c[N],st[N];
int ch[N][2];
char s[N];
int dfs(int u,int g){
    a[u]^=g;
    cnt++;
    if(u<=n){
        return a[u];
    }
    int x=dfs(ch[u][0],g^flag[ch[u][0]]);
    int y=dfs(ch[u][1],g^flag[ch[u][1]]);
    if(a[u]==2){
        if(x==0) c[ch[u][1]]=1;
        if(y==0) c[ch[u][0]]=1;
        return x&y;
    }
    else{
        if(x==1) c[ch[u][1]]=1;
        if(y==1) c[ch[u][0]]=1;
        return x|y;
    }
}
void dfs2(int u){
    if(u<=n) return;
    c[ch[u][0]]|=c[u];
    c[ch[u][1]]|=c[u];
    dfs2(ch[u][0]);
    dfs2(ch[u][1]);
}
int main()
{
    scanf("%[^\n]",s);
    n=read();
    ck=n;
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=0;s[i];i+=2){
        if(s[i]=='x'){
            int x=0;
            i++;
            while(s[i]!=' '){
                x=(x<<3)+(x<<1)+(s[i]^48);
                i++;
            }
            i--;
            st[++t]=x;
        }
        else if(s[i]=='&'){
            int x=st[t--];
            int y=st[t--];
            st[++t]=++ck;
            a[ck]=2;
            ch[ck][0]=x;
            ch[ck][1]=y;
        }
        else if(s[i]=='|'){
            int x=st[t--];
            int y=st[t--];
            st[++t]=++ck;
            a[ck]=3;
            ch[ck][0]=x;
            ch[ck][1]=y;
        }
        else if(s[i]=='!'){
            flag[st[t]]^=1;
        }
    }
    int ans=dfs(ck,flag[ck]);
    dfs2(ck);
    q=read();
    while(q--){
        int x=read();
        write((c[x]?ans:!ans));
        putchar('\n');
    }
    return 0;
}
