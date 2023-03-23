#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define reg register
#define N 200003
#define ls (u << 1)
#define rs (u << 1 | 1)
#define mid ((l + r) >> 1)
using namespace std;

inline void read(int &x)
{
    x = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
}

int n, q;
int a[N];
double sink, cosk;

struct Segment_Tree
{
    double sine[N << 2], cosi[N << 2];
    long long tag[N << 2];

    inline void pushup(int u)
    {
        sine[u] = sine[ls] + sine[rs];
        cosi[u] = cosi[ls] + cosi[rs];
    }

    inline void update(int u, double sinx, double cosx)
    {
        double sina = sine[u], cosa = cosi[u];
        sine[u] = sina * cosx + cosa * sinx;
        cosi[u] = cosa * cosx - sina * sinx;
    }

    inline void pushdown(int u)
    {
        if (!tag[u])
            return;
        double sinx = sin(tag[u]), cosx = cos(tag[u]);
        update(ls, sinx, cosx);
        update(rs, sinx, cosx);
        tag[ls] += tag[u];
        tag[rs] += tag[u];
        tag[u] = 0;
    }

    void build(int l, int r, int u)
    {
        if (l == r)
        {
            sine[u] = sin(a[l]);
            cosi[u] = cos(a[l]);
            return;
        }
        build(l, mid, ls);
        build(mid + 1, r, rs);
        pushup(u);
    }

    void modify(int nl, int nr, int l, int r, int u, int k)
    {
        if (nl <= l && r <= nr)
        {
            update(u, sink, cosk);
            tag[u] += k;
            return;
        }
        pushdown(u);
        if (nl <= mid)
            modify(nl, nr, l, mid, ls, k);
        if (nr > mid)
            modify(nl, nr, mid + 1, r, rs, k);
        pushup(u);
    }

    double query(int nl, int nr, int l, int r, int u)
    {
        if (nl <= l && r <= nr)
            return sine[u];
        double res = 0;
        pushdown(u);
        if (nl <= mid)
            res += query(nl, nr, l, mid, ls);
        if (nr > mid)
            res += query(nl, nr, mid + 1, r, rs);
        return res;
    }
} T;

int main()
{
    int op, l, r, k;
    read(n);
    for (reg int i = 1; i <= n; ++i)
        read(a[i]);
    T.build(1, n, 1);
    read(q);
    while (q--)
    {
        read(op), read(l), read(r);
        if (op == 1)
        {
            read(k);
            sink = sin(k), cosk = cos(k);
            T.modify(l, r, 1, n, 1, k);
        }
        else
            printf("%.1lf\n", T.query(l, r, 1, n, 1));
    }
    return 0;
}
