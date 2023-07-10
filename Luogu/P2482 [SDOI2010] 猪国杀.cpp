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
    //手牌,武器
    vector<char> cs;
    bool istiao,isdead,havewp;
    pig(){id=0;hp=4;cs.clear();istiao=isdead=havewp=0;}
}a[20];
int n,m,top,fcnt;
int jd[2];
bool think[20];
char pai[2003];

//判断死亡
bool cdead(int from,int to){
    if(a[to].hp>0) return 0;
    auto it=find(a[to].cs.begin(),a[to].cs.end(),'P');
    if(it==a[to].cs.end()){
        //死了
        a[to].isdead=1;
        a[a[to].pre].nxt=a[to].nxt;
        a[a[to].nxt].pre=a[to].pre;
        return 1;
    }
}

//出杀
void sha(int from,int to){
    if(a[from].id==1){
        //主猪
        //判断是否杀
        if(!think[to]) return;
        //去掉出的杀
        a[from].cs.erase(find(a[from].cs.begin(),a[from].cs.end(),'K'));
        //查找目标的闪
        auto it=find(a[to].cs.begin(),a[to].cs.end(),'D');
        if(it==a[to].cs.end()){
            //没有闪
            --a[to].hp;
            bool si=cdead(to);
            if(si==1){
                if(a[to].id==2){
                    //主猪杀死忠猪
                    a[from].cs.clear();
                    a[from].havewp=0;
                }
                else if(a[to].id==3){
                    //杀死反猪摸三张牌
                    
                }
            }
        }
        else{
            a[to].cs.erase(it);
        }
    }
    else if(a[from].id==2){
        //忠猪
        
    }
    else{
        //反猪
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
        p=a[now];
        p.cs.push_back(pai[top++]);
        if(top>m) top=m;
        p.cs.push_back(pai[top++]);
        //出牌
        //TODO 出牌从头判断
        bool finished=0;
        while(!finished){
            for(char card:p.cs){
                switch(card){
                    case 'P':{
                        if(p.hp==4) break;
                        else ++p.hp,finished=1;
                    }
                    case 'K':{
                        sha(now,p.nxt);
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