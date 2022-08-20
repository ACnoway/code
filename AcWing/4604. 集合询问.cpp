#include<iostream>
using namespace std;
string a[100005];
int main()
{
    int t,n=0,cnt;
    bool flag;
    cin>>t;
    char c;
    string s,t1,t2;
    while(t--){
        cin>>c>>s;
        switch(c){
            case '+':{
                a[++n]=s;
                break;
            }
            case '-':{
                for(int i=1;i<=n;++i) if(a[i]==s){a[i]="";break;}
                break;
            }
            case '?':{
                t1=s;
                for(int i=0;i<s.size();++i) s[i]=t1[s.size()-i-1];
                cnt=0;
                for(int i=1;i<=n;++i){
                    if(a[i]=="") continue;
                    flag=true;
                    t2=a[i];
                    for(int j=0;j<a[i].size();++j) t2[j]=a[i][a[i].size()-j-1];
                    t1=s;
                    for(int j=t1.size();j<20;++j) t1+='0';
                    for(int j=t2.size();j<20;++j) t2+='0';
                    //cout<<"s="<<t1<<endl;
                    //cout<<"a[i]="<<t2<<endl;
                    for(int j=0;j<t2.size();++j){
                        if((t2[j]-'0')%2!=t1[j]-'0'){
                            flag=false;
                            break;
                        }
                    }
                    if(flag) cnt++;
                }
                cout<<cnt<<endl;
                break;
            }
        }
    }
    return 0;
}