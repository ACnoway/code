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
    vector<char> cs,wp;
    bool istiao,isdead;
    pig(){id=0;hp=4;cs.clear();wp.clear();istiao=isdead=0;}
}a[20];
int n,m,top;
char pai[2003];

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
        else a[i].id=3;
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
                        sha(now);
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