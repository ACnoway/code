#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define Ede(i, u) for (int i = head[u]; i; i = e[i].nxt)
using namespace std;

bool Mb;

#define eb emplace_back
typedef pair<int, int> pii;
#define mp make_pair
#define fi first
#define se second

inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
        f = (c == '-') ? -1 : 1, c = getchar();
    while (c >= '0' && c <= '9')
        x = x * 10 + c - 48, c = getchar();
    return x * f;
}

const int N = 1e5 + 10;
int n, m, a[N];
vector<int> g[N];

int par[N], siz[N], son[N], dep[N];
void dfs1(int u, int fa)
{
    par[u] = fa, siz[u] = 1, dep[u] = dep[fa] + 1;
    for (auto v : g[u])
        if (v != fa)
        {
            dfs1(v, u), siz[u] += siz[v];
            if (siz[v] > siz[son[u]])
                son[u] = v;
        }
}

int tim, top[N], dfn[N], rev[N];
void dfs2(int u, int tp)
{
    top[u] = tp, dfn[u] = ++tim, rev[tim] = u;
    if (son[u])
        dfs2(son[u], tp);
    for (auto v : g[u])
        if (v != par[u] && v != son[u])
            dfs2(v, v);
}

int calc(int x, int y)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        x = par[top[x]];
    }
    return dep[x] < dep[y] ? x : y;
}

struct info
{
    int num, rng;
};
struct vec
{
    info f;
    int g;
};
struct mat
{
    info f[20];
    int g[20];
};
struct node
{
    mat up, dw;
} dat[N << 2];

bool operator<(const info &a, const info &b) {
    return a.num == b.num ? a.rng > b.rng : a.num < b.num;
}
info operator+(const int &a, const info &b) {
    return (info){a + b.num, b.rng};
}
vec operator+(const vec &a, const mat &b)
{
    vec c;
    c.f = min(a.f.num + b.f[a.f.rng], a.f.num + 1 + b.f[a.g]);
    c.g = b.g[a.g];
    return c;
}
mat operator+(const mat &a, const mat &b)
{
    mat c;
    rep(i, 0, 19)
        c.f[i] = min(a.f[i].num + b.f[a.f[i].rng], a.f[i].num + 1 + b.f[a.g[i]]),
        c.g[i] = b.g[a.g[i]];
    return c;
}

void pushup(int p)
{
    dat[p].dw = dat[p << 1].dw + dat[p << 1 | 1].dw;
    dat[p].up = dat[p << 1 | 1].up + dat[p << 1].up;
}

void bui(int p, int l, int r)
{
    if (l == r)
    {
        mat cur;
        cur.f[0] = (info){1, a[rev[l]] - 1}, cur.g[0] = a[rev[l]] - 1;
        rep(i, 1, 19) cur.f[i] = (info){0, i - 1}, cur.g[i] = max(a[rev[l]] - 1, i - 1);
        dat[p].up = dat[p].dw = cur;
        return;
    }
    int mid = (l + r) >> 1;
    bui(p << 1, l, mid), bui(p << 1 | 1, mid + 1, r), pushup(p);
}

void moi(int p, int l, int r, int k)
{
    if (l == r)
    {
        mat cur;
        cur.f[0] = (info){1, a[rev[l]] - 1}, cur.g[0] = a[rev[l]] - 1;
        rep(i, 1, 19) cur.f[i] = (info){0, i - 1}, cur.g[i] = max(a[rev[l]] - 1, i - 1);
        dat[p].up = dat[p].dw = cur;
        return;
    }
    int mid = (l + r) >> 1;
    if (k <= mid)
        moi(p << 1, l, mid, k);
    else
        moi(p << 1 | 1, mid + 1, r, k);
    pushup(p);
}

void app1(int p, int l, int r, int L, int R, vec &ans)
{
    if (L <= l && r <= R)
        return ans = ans + dat[p].up, void();
    int mid = (l + r) >> 1;
    if (R > mid)
        app1(p << 1 | 1, mid + 1, r, L, R, ans);
    if (L <= mid)
        app1(p << 1, l, mid, L, R, ans);
}

void app2(int p, int l, int r, int L, int R, vec &ans)
{
    if (L <= l && r <= R)
        return ans = ans + dat[p].dw, void();
    int mid = (l + r) >> 1;
    if (L <= mid)
        app2(p << 1, l, mid, L, R, ans);
    if (R > mid)
        app2(p << 1 | 1, mid + 1, r, L, R, ans);
}

void query(int x, int y)
{
    vec ans = (vec){(info){0, 0}, 0};
    int p = calc(x, y);

    while (top[x] != top[p])
        app1(1, 1, n, dfn[top[x]], dfn[x], ans), x = par[top[x]];
    if (x != p)
        app1(1, 1, n, dfn[p] + 1, dfn[x], ans);

    if (y != p)
    {
        y = par[y];
        vector<pii> stk;
        while (top[y] != top[p])
            stk.eb(mp(dfn[top[y]], dfn[y])), y = par[top[y]];
        if (dep[y] >= dep[p])
            stk.eb(mp(dfn[p], dfn[y]));
        reverse(stk.begin(), stk.end());
        for (auto o : stk)
            app2(1, 1, n, o.fi, o.se, ans);
    }

    printf("%d\n", ans.f.num);
}

bool Me;

int main()
{

    // cerr << (&Mb - &Me) / 1024.0 / 1024.0 << endl;

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    n = read();
    rep(i, 1, n) a[i] = read();
    rep(i, 2, n)
    {
        int u = read(), v = read();
        g[u].eb(v), g[v].eb(u);
    }

    dfs1(1, 0);
    dfs2(1, 1);
    bui(1, 1, n);

    m = read();
    while (m--)
    {
        char c[5];
        scanf("%s", c);
        int x = read(), y = read();
        if (c[0] == 'C')
            a[x] = y, moi(1, 1, n, dfn[x]);
        else
            query(x, y);
    }
    return 0;
}