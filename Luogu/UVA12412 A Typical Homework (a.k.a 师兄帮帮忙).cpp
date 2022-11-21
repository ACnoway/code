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
    //   score_sum pass_cnt
    int cid,ssum,pcnt;
    //顺序：语文 数学 英语 编程
    int scores[5];
    students(){sid=name="";cid=0;ssum=pcnt=0;}
}a[1000006];
struct classes{
    //每科总分 每科通过  总共（0:failed,1:pass1...）
    int sc[5],passes[5],passed[5];
    int cnt,scoresum;
    classes(){
        scoresum=0;
        for(int i=0;i<5;++i){
            sc[i]=passes[i]=0;
            passed[i]=0;
        }
    }
}b[50];
int op,cnt;
int rankton[410];
bool v[1000006];//是否没被删除
string subjects[4]={"Chinese","Mathematics","English","Programming"};
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
inline void come(int x){
    //sid占用
    m[a[x].sid]=1;
    //班级人数
    b[a[x].cid].cnt++;
    b[0].cnt++;
    for(int i=0;i<4;++i){
        //总分
        a[x].ssum+=a[x].scores[i];
        //各科总分
        b[a[x].cid].sc[i]+=a[x].scores[i];
        b[0].sc[i]+=a[x].scores[i];
        //通过
        if(a[x].scores[i]>=60){
            b[a[x].cid].passes[i]++;
            b[0].passes[i]++;
            a[x].pcnt++;
        }
    }
    //排名桶
    for(int i=a[x].ssum;i>=0;--i) rankton[i]++;
    //没被删除
    v[x]=1;
    //总分
    b[a[x].cid].scoresum+=a[x].ssum;
    b[0].scoresum+=a[x].ssum;
    //通过
    b[a[x].cid].passed[a[x].pcnt]++;
    b[0].passed[a[x].pcnt]++;
    for(int i=a[x].pcnt-1;i>0;--i){
        b[a[x].cid].passed[i]++;
        b[0].passed[i]++;
    }
}
inline void leave(int x){
    //取消sid占用
    m[a[x].sid]=0;
    //班级人数
    b[a[x].cid].cnt--;
    b[0].cnt--;
    //各科通过&总分
    for(int i=0;i<4;++i){
        b[a[x].cid].sc[i]-=a[x].scores[i];
        b[0].sc[i]-=a[x].scores[i];
        if(a[x].scores[i]>=60){
            b[a[x].cid].passes[i]--;
            b[0].passes[i]--;
        }
    }
    //排名桶
    for(int i=a[x].ssum;i>=0;--i) rankton[i]--;
    //被删除
    v[x]=0;
    //总分
    b[a[x].cid].scoresum-=a[x].ssum;
    b[0].scoresum-=a[x].ssum;
    //通过
    b[a[x].cid].passed[a[x].pcnt]--;
    b[0].passed[a[x].pcnt]--;
    for(int i=a[x].pcnt-1;i>0;--i){
        b[a[x].cid].passed[i]--;
        b[0].passed[i]--;
    }
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
        //存入列表
        a[++cnt]=in;
        come(cnt);
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
            if(!v[i]) continue;
            //sid唯一，找到可以直接退
            if(a[i].name==who){
                ans++;
                leave(i);
            }
            else if(a[i].sid==who){
                ans++;
                leave(i);
                break;
            }
        }
        cout<<ans<<" student(s) removed."<<endl;
    }
    return;
}
inline void outquery(int i){
    cout<<rankton[a[i].ssum+1]+1<<' '<<a[i].sid<<' '<<a[i].cid<<' '<<a[i].name<<' ';
    for(int j=0;j<4;++j) cout<<a[i].scores[j]<<' ';
    cout<<a[i].ssum<<' ';
    printf("%.2lf\n",a[i].ssum/4.0+eps);
    return;
}
void query(){
    string who;
    while(1){
        cout<<"Please enter SID or name. Enter 0 to finish."<<endl;
        cin>>who;
        if(who=="0") break;
        for(int i=1;i<=cnt;++i){
            if(!v[i]) continue;
            if(a[i].name==who){
                outquery(i);
            }
            else if(a[i].sid==who){
                outquery(i);
                break;
            }
        }
    }
    return;
}
void showr(){
    cout<<"Showing the ranklist hurts students' self-esteem. Don't do that."<<endl;
    return;
}
void shows(){
    int which;
    cout<<"Please enter class ID, 0 for the whole statistics."<<endl;
    cin>>which;
    classes need=b[which];
    for(int i=0;i<4;++i){
        cout<<subjects[i]<<endl;
        printf("Average Score: %.2lf\n",need.sc[i]/(double)need.cnt+eps);
        cout<<"Number of passed students: "<<need.passes[i]<<endl;
        cout<<"Number of failed students: "<<need.cnt-need.passes[i]<<endl<<endl;
    }
    cout<<"Overall:"<<endl;
    cout<<"Number of students who passed all subjects: "<<need.passed[4]<<endl;
    cout<<"Number of students who passed 3 or more subjects: "<<need.passed[3]<<endl;
    cout<<"Number of students who passed 2 or more subjects: "<<need.passed[2]<<endl;
    cout<<"Number of students who passed 1 or more subjects: "<<need.passed[1]<<endl;
    cout<<"Number of students who failed all subjects: "<<need.passed[0]<<endl<<endl;
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