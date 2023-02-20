// Problem: P1471 方差
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1471
// Memory Limit: 125 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#include <bits/extc++.h>
#define INF 0x7fffffff
#define MAXN 100005
#define eps 1e-9
#define foru(a, b, c) for (int a = b; a <= c; a++)
#define RT return 0;
#define db(x) cout << endl \
                   << x << endl;
#define LL long long
#define LXF int
#define RIN rin()
#define HH printf("\n")
using namespace std;
inline LXF rin()
{
    LXF x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}
int n, m;
inline int lb(int x) { return x & -x; }
class Tree
{
private:
    double c[MAXN];

public:
    void add(int x, double k)
    {
        for (; x <= n; x += lb(x))
        {
            c[x] += k;
        }
    }
    double ask(int x)
    {
        double ret = 0;
        for (; x; x -= lb(x))
        {
            ret += c[x];
        }
        return ret;
    }
} c, t;
double get(int x)
{
    return (x + 1) * c.ask(x) - t.ask(x);
}
double a[MAXN];
class SegTree
{
public:
    int l, r;
    double sum, psum, lz;
} tr[MAXN << 2];
inline int lc(int x) { return x << 1; }
inline int rc(int x) { return (x << 1) + 1; }
void push_up(int p)
{
    tr[p].sum = tr[lc(p)].sum + tr[rc(p)].sum;
    tr[p].psum = tr[lc(p)].psum + tr[rc(p)].psum;
}
void update(int p, double k)
{
    tr[p].lz += 1.0 * k;
    tr[p].psum += 1.0 * k * k * (tr[p].r - tr[p].l + 1) + 2.0 * k * tr[p].sum;
    tr[p].sum += 1.0 * k * (tr[p].r - tr[p].l + 1);
}
void push_down(int p)
{
    update(lc(p), tr[p].lz);
    update(rc(p), tr[p].lz);
    tr[p].lz = 0;
}
void build(int p, int l, int r)
{
    tr[p].l = l, tr[p].r = r;
    if (tr[p].l == tr[p].r)
    {
        update(p, a[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(lc(p), l, mid);
    build(rc(p), mid + 1, r);
    push_up(p);
}
void modify(int p, int nl, int nr, double k)
{
    if (tr[p].l > nr || tr[p].r < nl)
        return;
    if (tr[p].l >= nl && tr[p].r <= nr)
    {
        update(p, k);
        return;
    }
    push_down(p);
    modify(lc(p), nl, nr, k);
    modify(rc(p), nl, nr, k);
    push_up(p);
}
double qurey(int p, int nl, int nr)
{
    if (tr[p].l > nr || tr[p].r < nl)
        return 0;
    if (tr[p].l >= nl && tr[p].r <= nr)
    {
        return tr[p].psum;
    }
    push_down(p);
    return qurey(lc(p), nl, nr) + qurey(rc(p), nl, nr);
}
signed main()
{
    n = RIN, m = RIN;
    foru(i, 1, n)
    {
        cin >> a[i];
        c.add(i, a[i]);
        c.add(i + 1, -a[i]);
        t.add(i, i * a[i]);
        t.add(i + 1, -(i + 1) * a[i]);
    }
    build(1, 1, n);
    while (m--)
    {
        int opt = RIN, l = RIN, r = RIN;
        if (opt == 1)
        {
            double k;
            cin >> k;
            c.add(l, k);
            c.add(r + 1, -k);
            t.add(l, l * k);
            t.add(r + 1, -(r + 1) * k);
            modify(1, l, r, k);
        }
        else if (opt == 2)
        {
            printf("%.4lf\n", 1.0 * (get(r) - get(l - 1)) / (r - l + 1));
        }
        else
        {
            double pj = 1.0 * (get(r) - get(l - 1)) / (r - l + 1);
            double sum = qurey(1, l, r);
            // for(int i=l;i<=r;i++){
            // sum+=c.ask(i)*c.ask(i);
            // }
            printf("%.4lf\n", (sum + (r - l + 1) * pj * pj - 2 * pj * (get(r) - get(l - 1))) / (r - l + 1));
            // printf("%.4lf\n",sum);
        }
    }
    return 0;
}
