
#include <bits/stdc++.h>
#define INF 0x7fffffff
#define MAXN 2000005
#define eps 1e-9
#define foru(a, b, c) for (int a = b; a <= c; a++)
#define RT return 0;
#define LL long long
#define LXF int
#define RIN read_32()
#define HH printf("\n")
#define GC (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? 0 : *p1++)
using namespace std;
char buf[1 << 20], *p1, *p2;
inline int read_32()
{
    LXF X = 0, w = 0;
    char ch = 0;
    while (ch < '0' || ch > '9')
    {
        w |= ch == '-';
        ch = GC;
    }
    while (ch >= '0' && ch <= '9')
        X = (X << 3) + (X << 1) + (ch ^ 48), ch = GC;
    return w ? -X : X;
}
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int a[MAXN], n;
LL ans;
LL sum, t;
int mid;
int p[20] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int lf[9][MAXN], ltop, rf[9][MAXN], rtop;
void dfs(int s)
{
    if (s == mid + 1)
    {
        ltop++;
        for (int i = 0; i <= 8; i++)
        {
            lf[i][ltop] = sum % p[i + 1];
        }
        return;
    }
    dfs(s + 1);
    sum += a[s];
    dfs(s + 1);
    sum -= a[s];
}
void dfs1(int s)
{
    if (s == mid)
    {
        rtop++;
        for (int i = 0; i <= 8; i++)
        {
            rf[i][rtop] = sum % p[i + 1];
        }
        return;
    }
    dfs1(s - 1);
    sum += a[s];
    dfs1(s - 1);
    sum -= a[s];
}
bool cmp(int a, int b)
{
    return a > b;
}
signed main()
{
    n = RIN;
    mid = n >> 1;
    foru(i, 1, n)
    {
        a[i] = RIN;
    }
    dfs(1);
    dfs1(n);
    for (int i = 0; i <= 8; i++)
    {
        LL cnt = 0;
        sort(lf[i] + 1, lf[i] + 1 + ltop);
        sort(rf[i] + 1, rf[i] + 1 + rtop);
        int L = 1, R = 1;
        for (int r = rtop; r >= 1; r--)
        {
            while (R <= ltop && lf[i][R] + rf[i][r] < 5 * p[i])
                R++;
            while (L < R && lf[i][L] + rf[i][r] < 4 * p[i])
                L++;
            cnt += R - L;
        }
        for (int r = rtop; r >= 1; r--)
        {
            while (R <= ltop && lf[i][R] + rf[i][r] < 15 * p[i])
                R++;
            while (L < R && lf[i][L] + rf[i][r] < 14 * p[i])
                L++;
            cnt += R - L;
        }
        ans += cnt;
    }
    cout << ans;
    return 0;
}