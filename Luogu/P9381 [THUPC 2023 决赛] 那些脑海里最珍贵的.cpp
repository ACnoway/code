#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#define sc(x,y) strcmp(x,y)
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl
#endif
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
const int N=10;
struct player{
    //! 种族
    char species[N];
    //! 等级 体力上限 体力 主动技能等级 被动技能等级
    int level, maxhp, hp, zlevel, blevel;
    //!   基础攻击指数 基础防御指数 武器攻击力 技能加成
    double baseatk, basedef, weaponatk, skillbuff;
    //!  武器类型
    char weapon;
    bool isdead;
    player(){
        isdead=0;
        skillbuff=1.0;
    }
};
struct team{
    player p[N];
    //* 队员个数 当前队员
    int n,now;
    //!    防御加成  攻击加成
    double defbuff,atkbuff;
    team(){
        now=1;
        defbuff=atkbuff=1.0;
    }
}t[3];
int n,m,opteam;
char Team[2][10]={"North","South"};
double zhudong[3][6]={
        {0,0.1,0.12,0.15,0.17,0.2},
        {0,0.06,0.07,0.08,0.09,0.1},
        {0,2.1,2.17,2.24,2.32,2.4}
    },
    beidong[3][7]={
        {0.05,0.013,0.016,0.019,0.022,0.025},
        {0.1,0.01,0.02,0.03,0.04,0.05},
        {0.1,0.01,0.02,0.03,0.04,0.05}
    };
inline void init(){
    //* 初始化被动加成
    for(int i=0;i<2;++i){
        for(int j=1;j<=t[i].n;++j){
            if(sc(t[i].p[j].species,"Average")==0){
                t[i].defbuff+=beidong[1][t[i].p[j].blevel];
            }
            else if(sc(t[i].p[j].species,"Strong")==0){
                t[i].atkbuff+=beidong[2][t[i].p[j].blevel];
            }
        }
    }
}
inline void checkpassive(){
    double buffadd=0.0;
    for(int i=1;i<=t[opteam].n;++i){
        if(sc(t[opteam].p[i].species,"Weak")==0){
            buffadd+=beidong[0][t[opteam].p[i].blevel];
        }
    }
    int deltahp=0;
    for(int i=1;i<=t[opteam].n;++i){
        if(t[opteam].p[i].hp==t[opteam].p[i].maxhp||t[opteam].p[i].isdead) continue;
        deltahp=min((int)(buffadd*t[opteam].p[i].maxhp),t[opteam].p[i].maxhp-t[opteam].p[i].hp);
        
    }
}
int main()
{
    scanf("%d%d",&t[1].n,&t[0].n);
    for(int i=1;i<=t[i].n;++i){
        scanf("%s Lv=%d maxhp=%d atk=%lf def=%lf skillLv=%d passivesklLv=%d %c weaponatk=%lf",
        t[1].p[i].species,&t[1].p[i].level,&t[1].p[i].maxhp,&t[1].p[i].baseatk,&t[1].p[i].basedef,
        &t[1].p[i].zlevel,&t[1].p[i].blevel,&t[1].p[i].weapon,&t[1].p[i].weaponatk);
        t[1].p[i].hp=t[1].p[i].maxhp;
    }
    for(int i=1;i<=t[0].n;++i){
        scanf("%s Lv=%d maxhp=%d atk=%lf def=%lf skillLv=%d passivesklLv=%d %c weaponatk=%lf",
        t[0].p[i].species,&t[0].p[i].level,&t[0].p[i].maxhp,&t[0].p[i].baseatk,&t[0].p[i].basedef,
        &t[0].p[i].zlevel,&t[0].p[i].blevel,&t[0].p[i].weapon,&t[0].p[i].weaponatk);
        t[0].p[i].hp=t[0].p[i].maxhp;
    }
    int T;
    scanf("%d",&T);
    char leixing[15];
    init();
    for(int huiheshu=1;huiheshu<=T;++huiheshu){
        
        opteam=(huiheshu&1);
        //* 判断行动队员
        while(t[opteam].p[++t[opteam].now].isdead)
            if(t[opteam].now>t[opteam].n) t[opteam].now=1;
        
        checkpassive();
        scanf("%s",leixing);
        if(strcmp(leixing,"Basicattack")==0){
            //* 普通攻击
            cerr<<"普通攻击"<<endl;
            
        }
        else if(strcmp(leixing,"Specialattack")==0){
            //* 特殊攻击
            cerr<<"特殊攻击"<<endl;
            
        }
        else{
            //* 主动技能
            cerr<<"主动技能"<<endl;
            
        }
    }
    return 0;
}