#include <cstdio>
#include <queue>
#include <cstring>
#define INF 200000
#define MAXN 10010
#define MAXM 200050
using namespace std;
#define mi2(a, b) (a < b ? a : b)
int fst[MAXN], nt[MAXM], to[MAXM], v[MAXM], wei[MAXN], dq[MAXN];
int n, m, s, t;
void addline(int i, int a, int b, int c)
{
   to[i] = b;
   to[i ^ 1] = a;
   v[i] = c;
   v[i ^ 1] = 0;
   nt[i] = fst[a];
   nt[i ^ 1] = fst[b];
   fst[a] = i;
   fst[b] = i ^ 1;
}
bool bfs()
{
   queue<int> q;
   int u, i;
   memset(wei, 0x00, sizeof wei);
   q.push(s);
   wei[s] = 1;
   dq[s] = fst[s];
   while (!q.empty())
   {
      u = q.front();
      q.pop();
      for (i = fst[u]; i; i = nt[i])
      {
         if (wei[to[i]] == 0 && v[i] > 0)
         {
            wei[to[i]] = wei[u] + 1;
            dq[to[i]] = fst[to[i]];
            if (to[i] == t)
            {
               return true;
            }
            q.push(to[i]);
         }
      }
   }
   return false;
}
int find(int nw, int li)
{
   if (nw == t)
   {
      return li;
   }
   if (li == 0)
   {
      return 0;
   }
   int ans = 0;
   int u;
   for (int i = dq[nw]; i && ans < li; i = nt[i])
   {
      dq[nw] = i;
      if(wei[to[i]]!=wei[nw]+1)continue;
      u = find(to[i], mi2(v[i], li - ans));
      ans += u;
      v[i] -= u;
      v[i ^ 1] += u;
      if(u==0){
         wei[to[i]]=-1;
      }
   }
   return ans;
}
int dinic()
{
   int ans = 0;
   int u;
   while (bfs())
   {
      u = find(s, INF);
      if (!u)
      {
         continue;
      }
      ans += u;
   }
   return ans;
}
int main()
{
   scanf("%d%d%d%d", &n, &m, &s, &t);
   int a, b, c, i;
   for (i = 1; i <= m; ++i)
   {
      scanf("%d%d%d", &a, &b, &c);
      addline(i << 1, a, b, c);
   }
   printf("%d\n", dinic());
   return 0;
}