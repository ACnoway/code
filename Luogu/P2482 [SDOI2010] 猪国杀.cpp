#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
struct pig{
    //身份
    int id,hp;
    int pre,nxt;
    //他人身份
    int think[20];
    //手牌,武器
    vector<char> cs;
    bool istiao,isdead,havewp,shacnt;
    pig(){id=0;hp=4;cs.clear();istiao=isdead=havewp=0;}
}a[20];
int n,m,top=1,fcnt;
int jd[2];
bool think[20];
char pai[2003];

//摸牌
void getpai(pig &x,int ct){
    for(int i=1;i<=ct;++i){
        x.cs.push_back(pai[top++]);
        if(top>m) top=m;
    }
}

//胜利输出
void win(int who){
    if(who==1) cout<<"MP\n";
    else cout<<"FP\n";
    for(int i=1;i<=n;++i){
        if(a[i].isdead) cout<<"DEAD\n";
        else{
            for(char c:a[i].cs) putchar(c),putchar(' ');
            putchar('\n');
        }
    }
    cout.flush();
    exit(0);
}

//判断死亡
void cdead(int from,int to){
    if(a[to].hp>0) return;
    //找桃
    auto it=find(a[to].cs.begin(),a[to].cs.end(),'P');
    if(it==a[to].cs.end()){
        //死了
        a[to].isdead=1;
        if(a[to].id==-1){
            //反猪死了
            --fcnt;
            if(fcnt==0){
                win(1);
            }
            getpai(a[from],3);
        }
        else if(to==1){
            //主猪死了
            win(2);
        }
        else{
            //忠猪死了，判断是不是主猪杀的
            if(from==1){
                a[from].cs.clear();
                a[from].havewp=0;
            }
        }
        //死后行为
        a[a[to].pre].nxt=a[to].nxt;
        a[a[to].nxt].pre=a[to].pre;
        return;
    }
    else{
        //去掉桃
        a[to].cs.erase(it);
    }
}

//出杀
void sha(int from,int to){
    //去掉出的杀
    a[from].cs.erase(find(a[from].cs.begin(),a[from].cs.end(),'K'));
    //查找目标的闪
    auto it=find(a[to].cs.begin(),a[to].cs.end(),'D');
    if(it==a[to].cs.end()){//没有闪
        --a[to].hp;
        cdead(from,to);
    }
    else{
        //去掉闪
        a[to].cs.erase(it);
    }
}

//南猪入侵
void nzrq(int from){
    int x=a[from].nxt;
    while(x!=from){
        auto it=find(a[x].cs.begin(),a[x].cs.end(),'K');
        if(it!=a[x].cs.end()){
            //先找杀
            a[x].cs.erase(it);
        }
        else{
            //再找有没有人给他无懈
            
        }
        x=a[x].nxt;
    }
}

int main()
{
    //输入
    cin>>n>>m;
    string tmp;
    char tmp1;
    //初始情况
    for(int i=1;i<=n;++i){
        a[i].pre=i-1;
        a[i].nxt=i%n+1;
        cin>>tmp;
        if(tmp[0]=='M') a[i].id=1;
        else if(tmp[0]=='Z') a[i].id=2;
        else a[i].id=-1,++fcnt;
        for(int j=1;j<=4;++j){
            cin>>tmp1;
            a[i].cs.push_back(tmp1);
        }
    }
    //牌堆
    for(int i=1;i<=m;++i) cin>>pai[i];
    
    //开始游戏
    int now=1;
    while(1){
        //摸牌
        pig &p=a[now];
        getpai(p,2);
        //出牌
        bool finished=1;
        while(finished){
            finished=0;
            for(char card:p.cs){
                switch(card){
                    case 'P':{
                        //桃
                        if(p.hp==4) break;
                        else{
                            ++p.hp;
                            finished=1;
                        }
                        break;
                    }
                    case 'K':{
                        //杀
                        //TODO 判断是否能出杀
                        if(p.shacnt&&!p.havewp) break;
                        sha(now,p.nxt);
                        break;
                    }
                    case 'F':{
                        //决斗
                        
                    }
                    case 'N':{
                        //南猪入侵
                        nzrq(now);
                    }
                }
            }
        }
        //判断行为
        
        //判断死亡
        
        now=now%n+1;
    }
    return 0;
}