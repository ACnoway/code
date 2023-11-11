#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<iomanip>
#define double long double
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
const double eps=1e-6;
struct player{
    //! 种族     等级 体力上限 体力 主动技能等级 被动技能等级 aver主动技能回合数
    int species,level, maxhp, hp, zlevel, blevel, avercnt;
    //!   基础攻击指数 基础防御指数 武器攻击力 技能加成  aver主动技能效果
    double baseatk, basedef, weaponatk, skillbuff, averdamage;
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
        now=0;
        defbuff=atkbuff=1.0;
    }
}t[3];
int n,m,opteam;
//! 位置->编号   编号->位置
int num[2][10],idtop[2][10],bianhao[10]={0,5,3,1,2,4,6},haobian[10]={3,3,4,2,5,1,6};
char Team[2][10]={"North","South"};
double zhudong[3][6]={
        {0,0.1,0.12,0.15,0.17,0.2},
        {0,0.06,0.07,0.08,0.09,0.1},
        {0,2.1,2.17,2.24,2.32,2.4}
    },
    beidong[3][7]={
        {0,0.013,0.016,0.019,0.022,0.025},
        {0,0.01,0.02,0.03,0.04,0.05},
        {0,0.01,0.02,0.03,0.04,0.05}
    },
    speciebuff[4][4]={
        {1.0,0.9,1.1},
        {1.1,1.0,0.9},
        {0.9,1.1,1.0}
    },
    posbuff[6]={1.25,1.00,0.75,0.00,0.75,1.00};
inline void init(){
    //* 初始化被动加成
    for(int i=0;i<2;++i){
        for(int j=1;j<=t[i].n;++j){
            if(t[i].p[j].species==1){
                t[i].defbuff+=beidong[1][t[i].p[j].blevel];
            }
            else if(t[i].p[j].species==2){
                t[i].atkbuff+=beidong[2][t[i].p[j].blevel];
            }
        }
    }
}
inline void checkpassive(){
    double buffadd=0.0;
    for(int i=1;i<=t[opteam].n;++i){
        player nowplr=t[opteam].p[i];
        if(nowplr.isdead) continue;
        if(nowplr.species==0){
            buffadd+=beidong[0][nowplr.blevel];
        }
    }
    if(buffadd==0.0) return;
    // cerr<<buffadd<<endl;
    if(buffadd>0.05) buffadd=0.05;
    int deltahp=0;
    for(int pi=1;pi<=t[opteam].n;++pi){
        int i=idtop[opteam][pi];
        player& nowplr=t[opteam].p[i];
        if(nowplr.hp==nowplr.maxhp||nowplr.isdead) continue;
        deltahp=floor(buffadd*(double)(nowplr.maxhp)+eps);
        nowplr.hp+=min(nowplr.maxhp-nowplr.hp,deltahp);
        printf("%s %d recovered +%d hp -> %d/%d\n",
            Team[opteam],pi,deltahp,nowplr.hp,nowplr.maxhp);
    }
}
inline void checkdead(int who){
    player& nowplr=t[opteam^1].p[idtop[opteam^1][who]];
    if(nowplr.hp<=0){
        nowplr.isdead=1;
        if(nowplr.species==1) t[opteam^1].defbuff-=beidong[1][nowplr.blevel];
        else if(nowplr.species==2) t[opteam^1].atkbuff-=beidong[2][nowplr.blevel];
        nowplr.avercnt=0; nowplr.averdamage=0.0;
    }
}
inline void calcdamage(double baseatkpower,int target,int atkpos,int ddgpos){
    // cerr<<" baseatk= "<<baseatkpower<<endl;
    player &atkplr=t[opteam].p[idtop[opteam][t[opteam].now]],&defplr=t[opteam^1].p[idtop[opteam^1][target]];
    // cerr<<"skillbuff="<<atkplr.skillbuff<<" atkbuff="<<t[opteam].atkbuff
    // <<" spec= "<<speciebuff[atkplr.species][defplr.species]<<" posbuff= "<<posbuff[(atkpos-ddgpos+6)%6]<<endl;
    double atkpower=baseatkpower*atkplr.skillbuff*(1.1>t[opteam].atkbuff?t[opteam].atkbuff:1.1)
            *speciebuff[atkplr.species][defplr.species]*posbuff[(atkpos-ddgpos+6)%6],
        defpower=defplr.basedef*(1.1>t[opteam^1].defbuff?t[opteam^1].defbuff:1.1);
    int deltahp=floor(atkpower/defpower+eps);
    // cerr<<fixed<<setprecision(9)<<" basedef= "<<defplr.basedef<<"\ndefpower= "<<defpower<<"\ndeltahp= "<<atkpower/defpower<<" deltahp= "<<deltahp<<endl;
    defplr.hp-=min(defplr.hp,deltahp);
    printf("%s %d took %d damage from %s %d -> %d/%d\n",
        Team[opteam^1],target,deltahp,Team[opteam],t[opteam].now,defplr.hp,defplr.maxhp);
    checkdead(target);
    atkplr.skillbuff=1.0;
}
inline void putonggongji(int target,int atkpos,int ddgpos){
    player nowplr=t[opteam].p[idtop[opteam][t[opteam].now]];
    double baseatkpower=nowplr.baseatk*nowplr.weaponatk;
    calcdamage(baseatkpower,target,atkpos,ddgpos);
}
inline void teshugongji(int target,int atkpos,int ddgpos){
    player &nowplr=t[opteam].p[idtop[opteam][t[opteam].now]];
    double tmpbuff=nowplr.skillbuff;
    if(nowplr.weapon=='B'){
        double baseatkpower=nowplr.baseatk*nowplr.weaponatk*1.25;
        calcdamage(baseatkpower,target,atkpos,ddgpos);
    }
    else if(nowplr.weapon=='G'){
        double damagecnt=1.0;
        int mid=idtop[opteam^1][target],l=mid-1,r=mid+1;
        while(l>0&&t[opteam^1].p[l].isdead) --l;
        while(r<=t[opteam^1].n&&t[opteam^1].p[r].isdead) ++r;
        if(l>0) damagecnt+=1.0;
        if(r<=t[opteam^1].n) damagecnt+=1.0;
        double x=135.0/damagecnt/100.0,
            baseatkpower=nowplr.baseatk*nowplr.weaponatk*x;
        // cerr<<"x="<<x<<" base= "<<nowplr.baseatk<<" weapon= "<<nowplr.weaponatk<<endl;
        calcdamage(baseatkpower,num[opteam^1][mid],atkpos,ddgpos);
        if(l>0) nowplr.skillbuff=tmpbuff,calcdamage(baseatkpower,num[opteam^1][l],atkpos,ddgpos);
        if(r<=t[opteam^1].n) nowplr.skillbuff=tmpbuff,calcdamage(baseatkpower,num[opteam^1][r],atkpos,ddgpos);
    }
    else{
        int mid=idtop[opteam^1][target],l=mid-1,r=mid+1;
        while(l>0&&t[opteam^1].p[l].isdead) --l;
        while(r<=t[opteam^1].n&&t[opteam^1].p[r].isdead) ++r;
        double baseatkpower=nowplr.baseatk*nowplr.weaponatk;
        calcdamage(baseatkpower*1.15,num[opteam^1][mid],atkpos,ddgpos);
        if(l>0) nowplr.skillbuff=tmpbuff,calcdamage(baseatkpower*0.23,num[opteam^1][l],atkpos,ddgpos);
        if(r<=t[opteam^1].n) nowplr.skillbuff=tmpbuff,calcdamage(baseatkpower*0.23,num[opteam^1][r],atkpos,ddgpos);
    }
}
inline void zhudongjineng(int target){
    player nowplr=t[opteam].p[idtop[opteam][t[opteam].now]];
    if(nowplr.species==0){
        printf("%s %d applied Weak skill to %s %d\n",
            Team[opteam],t[opteam].now,Team[opteam],target);
        // cerr<<"skill 0"<<endl;
        player& tarplr=t[opteam].p[idtop[opteam][target]];
        if(tarplr.hp==tarplr.maxhp) return;
        int deltahp=floor(tarplr.maxhp*zhudong[0][nowplr.zlevel]+eps);
        tarplr.hp+=min(tarplr.maxhp-tarplr.hp,deltahp);
        printf("%s %d recovered +%d hp -> %d/%d\n",
            Team[opteam],target,deltahp,tarplr.hp,tarplr.maxhp);
    }
    else if(nowplr.species==1){
        printf("%s %d applied Average skill to %s %d\n",
            Team[opteam],t[opteam].now,Team[opteam^1],target);
        // cerr<<"skill 1"<<endl;
        player& tarplr=t[opteam^1].p[idtop[opteam^1][target]];
        tarplr.avercnt=3;
        tarplr.averdamage=zhudong[1][nowplr.zlevel];
    }
    else{
        printf("%s %d applied Strong skill to %s %d\n",
            Team[opteam],t[opteam].now,Team[opteam],target);
        // cerr<<"skill 2"<<endl<<"target: "<<target<<" id: "<<idtop[opteam][target]<<endl;
        t[opteam].p[idtop[opteam][target]].skillbuff=zhudong[2][nowplr.zlevel];
    }
}
inline void skilldamage(){
    for(int i=1;i<=t[opteam^1].n;++i){
        player& nowplr=t[opteam^1].p[idtop[opteam^1][i]];
        if(!nowplr.isdead&&nowplr.avercnt>0){
            int deltahp=floor(nowplr.maxhp*nowplr.averdamage+eps);
            nowplr.hp-=min(nowplr.hp,deltahp);
            printf("%s %d took %d damage from skill -> %d/%d\n",
                Team[opteam^1],i,deltahp,nowplr.hp,nowplr.maxhp);
            --nowplr.avercnt;
            checkdead(i);
        }
    }
}
inline void endhuihe(){
    skilldamage();
    for(int i=0;i<2;++i){
        printf("%s:",Team[i]);
        for(int j=1;j<=t[i].n;++j){
            printf(" %d/%d",t[i].p[j].hp,t[i].p[j].maxhp);
        }
        putchar('\n');
    }
    putchar('\n');
}
inline void checkwin(){
    for(int tm=0;tm<2;++tm){
        int cnt=0;
        for(int i=1;i<=t[tm].n;++i){
            if(t[tm].p[i].hp<=0) ++cnt;
        }
        if(cnt==t[tm].n){
            printf("Team %s won.\n",Team[tm^1]);
            return;
        }
    }
}
int main()
{
    // freopen("P9381.in","r",stdin);
    // freopen("P9381.out","w",stdout);
    scanf("%d%d",&t[1].n,&t[0].n);
    
    int l=min(haobian[t[1].n],haobian[t[1].n-1]),r=max(haobian[t[1].n],haobian[t[1].n-1]);
    for(int i=l;i<=r;++i)
        num[1][i-l+1]=bianhao[i],idtop[1][bianhao[i]]=i-l+1;
    // cerr<<"南队:"<<endl;
    // for(int i=1;i<=t[1].n;++i) cerr<<"pos= "<<idtop[1][i]<<endl;
    
    for(int pi=1;pi<=t[1].n;++pi){
        int i=idtop[1][pi];
        char specie[20];
        scanf("%s Lv=%d maxhp=%d atk=%Lf def=%Lf skillLv=%d passivesklLv=%d %c weaponatk=%Lf",
        specie,&t[1].p[i].level,&t[1].p[i].maxhp,&t[1].p[i].baseatk,&t[1].p[i].basedef,
        &t[1].p[i].zlevel,&t[1].p[i].blevel,&t[1].p[i].weapon,&t[1].p[i].weaponatk);
        t[1].p[i].hp=t[1].p[i].maxhp;
        if(sc(specie,"Weak")==0) t[1].p[i].species=0;
        else if(sc(specie,"Average")==0) t[1].p[i].species=1;
        else if(sc(specie,"Strong")==0) t[1].p[i].species=2;
    }
    
    l=min(haobian[t[0].n],haobian[t[0].n-1]),r=max(haobian[t[0].n],haobian[t[0].n-1]);
    for(int i=l;i<=r;++i)
        num[0][i-l+1]=bianhao[i],idtop[0][bianhao[i]]=i-l+1;
    // cerr<<"北队:"<<endl;
    // for(int i=1;i<=t[0].n;++i) cerr<<"pos= "<<idtop[0][i]<<endl;
    
    for(int pi=1;pi<=t[0].n;++pi){
        int i=idtop[0][pi];
        char specie[20];
        scanf("%s Lv=%d maxhp=%d atk=%Lf def=%Lf skillLv=%d passivesklLv=%d %c weaponatk=%Lf",
        specie,&t[0].p[i].level,&t[0].p[i].maxhp,&t[0].p[i].baseatk,&t[0].p[i].basedef,
        &t[0].p[i].zlevel,&t[0].p[i].blevel,&t[0].p[i].weapon,&t[0].p[i].weaponatk);
        t[0].p[i].hp=t[0].p[i].maxhp;
        if(sc(specie,"Weak")==0) t[0].p[i].species=0;
        else if(sc(specie,"Average")==0) t[0].p[i].species=1;
        else if(sc(specie,"Strong")==0) t[0].p[i].species=2;
    }
    int T;
    scanf("%d",&T);
    char leixing[15];
    init();
    for(int huiheshu=1;huiheshu<=T;++huiheshu){
        
        opteam^=1;
        //* 判断行动队员
        do{
            if(t[opteam].now==t[opteam].n) t[opteam].now=0;
        }while(t[opteam].p[idtop[opteam][++t[opteam].now]].isdead);
        // cerr<<"team: "<<opteam<<" player: "<<t[opteam].now<<endl;
        checkpassive();
        scanf("%s",leixing);
        if(strcmp(leixing,"Basicattack")==0){
            //* 普通攻击
            // cerr<<"普通攻击"<<endl;
            int target,atkpos,ddgpos;
            scanf(" target=%d atkpos=%d ddgpos=%d",&target,&atkpos,&ddgpos);
            putonggongji(target,atkpos,ddgpos);
        }
        else if(strcmp(leixing,"Specialattack")==0){
            //* 特殊攻击
            // cerr<<"特殊攻击"<<endl;
            int target,atkpos,ddgpos;
            scanf(" target=%d atkpos=%d ddgpos=%d",&target,&atkpos,&ddgpos);
            teshugongji(target,atkpos,ddgpos);
        }
        else{
            //* 主动技能
            // cerr<<"主动技能"<<endl;
            int target;
            scanf(" target=%d",&target);
            zhudongjineng(target);
            
        }
        
        endhuihe();
    }
    checkwin();
    return 0;
}