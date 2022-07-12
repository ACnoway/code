#include <iostream>
#include <cstdio>
using namespace std;
inline string read(){
    string x="";
    char c=getchar();
    while(c<65||(c>90&&c<97)||c>122) c=getchar();
    while((c>=65&&c<=90)||(c>=97&&c<=122)){
        x+=c;
        c=getchar();
    }
    return x;
}
int main()
{
    string k,m;
    k=read();
    m=read();
    int kl=k.size(),ml=m.size();
    for(int i=0;i<ml;++i){
        char kk=k[i%kl],mm=m[i];
        if(kk<=90&&mm>90) kk+=32;
        else if(kk>90&&mm<=90) kk-=32;
        if(mm<kk) kk-=26;
        if(mm<=90) putchar(mm-kk+65);
        else putchar(mm-kk+97);
    }
    return 0;
}
//(x_i+k_i-'A')%'A'=m_i