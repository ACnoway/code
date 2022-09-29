#include<iostream>
#include<cmath>
using namespace std;
int n,tmp,flag,x[2];
int ans[1000006];
char zimu[27];
string a,b,c;
int main()
{
    for(int i=1;i<=26;++i) zimu[i]=i+'A'-1;
    zimu[0]='\0';
    cin>>n;
    while(n--){
        cin>>a;
        b="";
        flag=0;
        tmp=0;
        x[0]=0;x[1]=0;
        for(int i=0;i<a.size();++i){
            if(a[i]=='C'&&i>0&&a[i-1]>='0'&&a[i-1]<='9') flag=1;
        }
        if(flag){
            flag=0;
            for(int i=0;i<a.size();++i){
                if(a[i]>='0'&&a[i]<='9') x[flag]=(x[flag]<<3)+(x[flag]<<1)+(a[i]^48);
                if(a[i]=='C') flag=1;
            }
            //x[1]--;
            while(x[1]){
                if(x[1]>26) b+='Z';
                else b+=(x[1]-1)%26+'A';
                //cout<<x[1]<<' '<<b<<endl;
                x[1]/=27;
            }
            cout<<b<<x[0]<<endl;
        }
        else{
            for(int i=0;i<a.size();++i){
                if(a[i]>='A'&&a[i]<='Z') b=a[i]+b;
                else x[1]=(x[1]<<3)+(x[1]<<1)+(a[i]^48);
            }
            for(int i=0;i<b.size();++i){
                x[0]+=(b[i]-'A'+1)*pow(26,i);
            }
            cout<<'R'<<x[1]<<'C'<<x[0]<<endl;
        }
    }
    return 0;
}