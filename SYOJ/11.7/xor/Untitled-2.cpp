#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define N (int)(1e6 + 10)
#define fp(i, l, r) for (re int i = (l); i <= (r); ++i)
#define il inline
#define re register
il int read()
{ // 卡常快读当然是必不可少的啦
    re int x = 0, f = 1;
    re char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}

int n, m, bl, a[N], b[N], cnt[N], ans[N], XORsum;
struct query
{
    int l, r, be, id;
} q[N];
bool cmp(query a, query b)
{
    return a.be ^ b.be ? a.l < b.l : a.be & 1 ? a.r < b.r
                                              : a.r > b.r;
}

il void add(int x)
{
    if (++cnt[a[x]] > 1)
        XORsum ^= b[a[x]];
}
il void del(int x)
{
    if (--cnt[a[x]] > 0)
        XORsum ^= b[a[x]];
}

int main()
{
    n = read();
    fp(i, 1, n) a[i] = read(), b[i] = a[i];
    sort(b + 1, b + n + 1); // 离散化
    int tot = unique(b + 1, b + n + 1) - b - 1;
    fp(i, 1, n) a[i] = lower_bound(b + 1, b + tot + 1, a[i]) - b;
    m = read();
    bl = n / pow(m, 0.455); // 灵魂取块长
    fp(i, 1, m)
    {
        q[i].l = read();
        q[i].r = read();
        q[i].id = i;
        q[i].be = q[i].l / bl;
    }
    sort(q + 1, q + m + 1, cmp);
    re int l = q[1].l, r = q[1].l - 1;
    fp(i, 1, m)
    {
        while (l < q[i].l)
            del(l++);
        while (l > q[i].l)
            add(--l);
        while (r < q[i].r)
            add(++r);
        while (r > q[i].r)
            del(r--);
        ans[q[i].id] = XORsum;
    }
    fp(i, 1, m) printf("%d\n", ans[i]);
    return 0;
}
