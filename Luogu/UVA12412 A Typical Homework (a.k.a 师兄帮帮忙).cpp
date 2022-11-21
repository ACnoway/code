/*
记录总分及有效人数，平均分现算
添加和删除函数中要更新总分和overall
*/

#include<iostream>
#include<cstdio>
#include<unordered_map>
using namespace std;
const double eps=1e-5;
struct students{
    string sid,name;
    int cid;
    //顺序：语文 数学 英语 编程
    int scores[4];
}a[1000006];
//每科平均分
double aver[4];
//  每科通过  每科没通过 总共（0:failed,1:pass1...）
int passes[4],fails[4],passed[5];
int op,cnt,now;
bool v[1000006];//是否没被删除
//记录sid是否出现过
unordered_map<string,bool> m;
inline void outmain(){
cout<<R"(Welcome to Student Performance Management System (SPMS).

1 - Add
2 - Remove
3 - Query
4 - Show ranking
5 - Show Statistics
0 - Exit
)"<<endl;
}
void add(){
    students in;
    while(1){
        cout<<"Please enter the SID, CID, name and four scores. Enter 0 to finish."<<endl;
        cin>>in.sid;
        if(in.sid=="0") break;
        cin>>in.cid>>in.name;
        for(int i=0;i<4;++i) cin>>in.scores[i];
        if(m[in.sid]){
            cout<<"Duplicated SID."<<endl;
            continue;
        }
        m[in.sid]=1;
        for(int i=0;i<4;++i){
            if(in.scores[i]>=60) passes[i]++;
            else fails[i]++;
        }
        a[++cnt]=in;
        now++;
        v[cnt]=1;
    }
    return;
}
void remove(){
    int ans=0;
    string who;
    while(1){
        ans=0;
        cout<<"Please enter SID or name. Enter 0 to finish."<<endl;
        cin>>who;
        if(who=="0") break;
        for(int i=1;i<=cnt;++i){
            if(a[i].sid==who&&v[i]){
                v[i]=0;
                ans++;
                for(int j=0;j<4;++j){
                    if(a[i].scores[j]>=60) passes[j]--;
                    else fails[j]--;
                }
                break;
            }
            else if(a[i].name==who&&v[i]){
                v[i]=0;
                ans++;
                for(int j=0;j<4;++j){
                    if(a[i].scores[j]>=60) passes[j]--;
                    else fails[j]--;
                }
            }
        }
        now-=ans;
        cout<<
    }
    return;
}
void query(){
    return;
}
void showr(){
    cout<<"Showing the ranklist hurts students' self-esteem. Don't do that."<<endl;
    return;
}
void shows(){
    return;
}
int main()
{
    while(1){
        outmain();
        cin>>op;
        if(!op) break;
        switch(op){
            case 1:{
                add();
                break;
            }
            case 2:{
                remove();
                break;
            }
            case 3:{
                query();
                break;
            }
            case 4:{
                showr();
                break;
            }
            case 5:{
                shows();
                break;
            }
        }
    }
    return 0;
}