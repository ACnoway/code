#include <bits/stdc++.h>
//#include <windows.h>
#define int long long
#define db double

#define x1 Gotoh_HitorI
#define x2 Kita_IkuYo
#define y1 Ijichi_NijikA
#define y2 Yamada_RYo
#define x0 Ijichi_SeikA
#define y0 Katarai_KihaN

int read() {

    int _ = 0, __ = 1;
    char ___ = getchar();
    while (___ > '9' || ___ < '0') {
        if (___ == '-') __ = -1;
        ___ = getchar();
    }
    while (___ >= '0' && ___ <= '9') {
        _ = _ * 10 + ___ - '0';
        ___ = getchar();
    }
    return __ == 1 ? _ : -_;

}

#define check1 puts("我永远喜欢02！！！！")
#define check2 puts("电磁炮真是太可爱了qwq")
#define check3 puts("辉夜大小姐想要来点兔女郎学姐")
#define check4 puts("我去，初音未来！")
#define check5 puts("I love 002 forever.")
#define check6 puts("为斯卡蒂献上心脏！！！")
#define check7 puts("\n——————————————————————————————————")

const int INF = 1e18, inf = 1e9, Uinf = 1ll << 31;
const double eps = 1e-7, pi_ = acos(-1.0);
const double inf_double = 1e9 + 0.114514, INF_double = 1e18 + 0.1919810;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
const int dx8[] = {1, -1, 1, -1, -1, 1, 0, 0};
const int dy8[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int bighsh = 2000000011;

int gcd(int __, int ___) {
    if (!__) return 1;
    return ___ == 0 ? __ : gcd(___, __ % ___);
}
int lcm(int __, int ___) {
    return __ * ___ / gcd(__, ___);
}
double disttt_xy(double x_1, double y_1, double x_2, double y_2) {
    return sqrt((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2));
}
bool cmp_ge(int a, int b) {
    return a > b;
}
bool eq0(double fixdf) {
    return fabs(fixdf) < eps;
}
bool eq(double dbnum1, double dbnum2) {
    return fabs(dbnum1 - dbnum2) < eps;
}

#define Strelitzia_ 0
int n,m,ans;
int a[502][502];
struct node{
    int u,v,w;
    bool operator <(const node &x)const{
        return w<x.w;
    }
}e[1000006];
int idx,p[502];
int find(int x){
    while(p[x]!=x) x=p[x]=p[p[x]];
    return p[x];
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y) p[x]=y;
}
void addedge(int u,int v,int w){
    e[++idx].u=u;
    e[idx].v=v;
    e[idx].w=w;
}
void kruskal(){
    int cnt=1;
    for(int i=1;i<=idx&&cnt<=n;++i){
        if(find(e[i].u)!=find(e[i].v)){
            ++cnt;
            ans+=e[i].w;
            merge(e[i].u,e[i].v);
        }
    }
}
signed main()
{
    m=read();
    n=read();
    int x;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            x=read();
            if(i<j&&x){
                addedge(i,j,x);
            }
        }
    }
    for(int i=1;i<=n;++i) addedge(0,i,m);
    for(int i=0;i<=n;++i) p[i]=i;
    std::sort(e+1,e+idx+1);
    kruskal();
    std::cout<<ans<<std::endl;
}
/*

             「蒼い惑星　ひとりぼっち」
            「いっぱいの音を聞いてきた」
               「回り続けて　幾億年」
               「一瞬でもいいから…」

                    「聞いて」

                    「聴けよ」

        「わたし　わたし　わたしはここにいる」
    「殴り書きみたいな音　出せない状態で叫んだよ」
     「なんかになりたい　なりたい　何者かでいい」
             「馬鹿なわたしは歌うだけ」
            「ぶちまけちゃおうか　星に」

*/
