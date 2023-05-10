#include <bits/stdc++.h>
//#include <windows.h>
//#define int long long
//#define db double
//
//#define x1 Gotoh_HitorI
//#define x2 Kita_IkuYo
//#define y1 Ijichi_NijikA
//#define y2 Yamada_RYo
//#define x0 Ijichi_SeikA
//#define y0 Katarai_KihaN
//
//int read() {
//
//  int _ = 0, __ = 1;
//      char ___ = getchar();
//          while (___ > '9' || ___ < '0') {
//                  if (___ == '-') __ = -1;
//                          ___ = getchar();
//                              }
//                                  while (___ >= '0' && ___ <= '9') {
//                                          _ = _ * 10 + ___ - '0';
//                                                  ___ = getchar();
//                                                      }
//                                                          return __ == 1 ? _ : -_;
//
//                                                          }
//
//                                                          #define check1 puts("我永远喜欢02！！！！")
//                                                          #define check2 puts("电磁炮真是太可爱了qwq")
//                                                          #define check3 puts("辉夜大小姐想要来点兔女郎学姐")
//                                                          #define check4 puts("我去，初音未来！")
//                                                          #define check5 puts("I love 002 forever.")
//                                                          #define check6 puts("为斯卡蒂献上心脏！！！")
//                                                          #define check7 puts("\n——————————————————————————————————")
//
//                                                          const int INF = 1e18, inf = 1e9, Uinf = 1ll << 31;
//                                                          const double eps = 1e-7, pi_ = acos(-1.0);
//                                                          const double inf_double = 1e9 + 0.114514, INF_double = 1e18 + 0.1919810;
//                                                          const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//                                                          const int dx8[] = {1, -1, 1, -1, -1, 1, 0, 0};
//                                                          const int dy8[] = {0, 0, 1, -1, 1, -1, 1, -1};
//                                                          const int bighsh = 2000000011;
//
//                                                          int gcd(int __, int ___) {
//                                                              if (!__) return 1;
//                                                                  return ___ == 0 ? __ : gcd(___, __ % ___);
//                                                                  }
//                                                                  int lcm(int __, int ___) {
//                                                                      return __ * ___ / gcd(__, ___);
//                                                                      }
//                                                                      double disttt_xy(double x_1, double y_1, double x_2, double y_2) {
//                                                                          return sqrt((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2));
//                                                                          }
//                                                                          bool cmp_ge(int a, int b) {
//                                                                              return a > b;
//                                                                              }
//                                                                              bool eq0(double fixdf) {
//                                                                                  return fabs(fixdf) < eps;
//                                                                                  }
//                                                                                  bool eq(double dbnum1, double dbnum2) {
//                                                                                      return fabs(dbnum1 - dbnum2) < eps;
//                                                                                      }
//
//                                                                                      #define Strelitzia_ 0
//                                                                                      int n,m;
//                                                                                      int a[100005];
//                                                                                      signed main()
//                                                                                      {
//                                                                                          n=read();
//                                                                                              m=read();
//                                                                                                  int ans=0;
//                                                                                                      for(int i=1;i<=n;++i){
//                                                                                                              a[i]=read();
//                                                                                                                  }
//                                                                                                                      std::sort(a+1,a+n+1);
//                                                                                                                          for(int i=2;i<n;++i){
//                                                                                                                                  ans+=a[i];
//                                                                                                                                      }
//                                                                                                                                          if(a[n]*(n-2)-ans>m) std::cout<<ans+m<<std::endl;
//                                                                                                                                              else{
//                                                                                                                                                      int now=m-a[n]*(n-2)+ans;
//                                                                                                                                                              std::cout<<a[n]*(n-2)+now*(n-2)/(n-1)<<std::endl;
//                                                                                                                                                                  }
//                                                                                                                                                                  }
//                                                                                                                                                                  /*
//
//                                                                                                                                                                               「蒼い惑星　ひとりぼっち」
//                                                                                                                                                                                           「いっぱいの音を聞いてきた」
//                                                                                                                                                                                                          「回り続けて　幾億年」
//                                                                                                                                                                                                                         「一瞬でもいいから…」
//
//                                                                                                                                                                                                                                             「聞いて」
//
//                                                                                                                                                                                                                                                                 「聴けよ」
//
//                                                                                                                                                                                                                                                                         「わたし　わたし　わたしはここにいる」
//                                                                                                                                                                                                                                                                             「殴り書きみたいな音　出せない状態で叫んだよ」
//                                                                                                                                                                                                                                                                                  「なんかになりたい　なりたい　何者かでいい」
//                                                                                                                                                                                                                                                                                               「馬鹿なわたしは歌うだけ」
//                                                                                                                                                                                                                                                                                                           「ぶちまけちゃおうか　星に」
//
//                                                                                                                                                                                                                                                                                                           */
