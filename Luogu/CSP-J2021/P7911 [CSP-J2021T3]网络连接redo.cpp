#include<iostream>
#include<cstdio>
#include<sstream>
#include<cstring>
#include<map>
using namespace std;
//存放服务器地址和编号
map<string,int> m;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        char op[30],ad[30];
        cin>>op>>ad;
        int a,b,c,d,e;
        //从字符串内读入，判断格式和数字个数是否正确
        if(sscanf(ad,"%d.%d.%d.%d:%d",&a,&b,&c,&d,&e)!=5){
            cout<<"ERR"<<endl;
            continue;
        }
        //暴力判断数字是否超出范围
        if(a<0||a>255||b<0||b>255||c<0||c>255||d<0||d>255||e<0||e>65535){
            cout<<"ERR"<<endl;
            continue;
        }
        //判断是否有前导0
        //把所有的数字按照正确格式存进一个字符串，
        //因为在输入数字时前导0会被省略，
        //所以若两个字符串相等则没有前导0
        char s[30];
        //sprintf跟sscanf用法基本相同，
        //sscanf是从字符串内输入，sprintf是输出到字符串内
        sprintf(s,"%d.%d.%d.%d:%d",a,b,c,d,e);
        if(strlen(s)!=strlen(ad)){
            //提前判断s的长度是否改变，省去后面循环
            cout<<"ERR"<<endl;
            continue;
        }
        bool ok=1;
        for(int j=0;j<strlen(ad);++j){
            if(ad[j]!=s[j]){
                ok=0;
                break;
            }
        }
        if(!ok){
            cout<<"ERR"<<endl;
            continue;
        }
        //判断地址格式完毕，将地址保存
        if(op[0]=='S'){
            if(m[ad]==0){
                //如果没有地址相同的服务器
                //存储这个服务器的编号
                m[ad]=i;
                cout<<"OK"<<endl;
                continue;
            }
            else{
                cout<<"FAIL"<<endl;
                continue;
            }
        }
        else{
            if(m[ad]==0){
                //如果没有客户机要连接的地址的服务器
                cout<<"FAIL"<<endl;
                continue;
            }
            else{
                cout<<m[ad]<<endl;
                continue;
            }
        }
    }
    return 0;
}