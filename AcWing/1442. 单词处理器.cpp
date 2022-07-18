#include <iostream>
#include <cstdio>
#include <cctype>
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
inline string rs(){
    string s="";
    char c=getchar();
    while(!isalpha(c)) c=getchar();
    while(isalpha(c)){
        s+=c;
        c=getchar();
    }
    return s;
}
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int n,k,sn;
string a;
int main()
{
    n=read();
    k=read();
    for(int i=0;i<n;++i){
        a=rs();
        if(sn==0){
            cout<<a;
            sn+=a.size();
        }
        else if(a.size()+sn<=k&&sn!=0){
            cout<<' '<<a;
            sn+=a.size();
        } 
        else if(a.size()+sn>k){
            cout<<endl<<a;
            sn=a.size();
        }
    }
    return 0;
}