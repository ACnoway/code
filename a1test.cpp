#include <bits/stdc++.h>
#define ll long long
using namespace std;
namespace FGF
{
    int n, m, s;
    const int N = 2505;
    struct edg
    {
        int u, v, w;
        edg(){};
        edg(int _u, int _v, int _w) : u(_u), v(_v), w(_w){};
    };
    bool operator<(edg a, edg b)
    {
        return a.w < b.w;
    }
    int fa[N], bel[N], sum, du[N];
    int find(int x)
    {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    void work()
    {
        scanf("%d%d%d", &n, &m, &s);
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            du[u]++, du[v]++;
            sum += abs(u - v);
            fa[find(u)] = find(v);
        }
        for (int i = 1; i <= n; i++)
            bel[i] = find(i);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                fa[j] = j;
            du[s]++, du[i]++;
            fa[find(bel[s])] = find(bel[i]);
            ll ans = sum, pre = 0;
            for (int j = 1; j <= n; j++)
                if (du[j] & 1)
                {
                    if (pre)
                    {
                        ans += j - pre;
                        for (int k = pre; k < j; k++)
                            fa[find(bel[k])] = fa[find(bel[j])];
                        pre = 0;
                    }
                    else
                        pre = j;
                }
            vector<edg> g;
            for (int j = 1; j <= n; j++)
                if (du[j])
                {
                    if (pre && find(bel[j]) != find(bel[pre]))
                        g.push_back(edg(bel[j], bel[pre], abs(j - pre)));
                    pre = j;
                }
            sort(g.begin(), g.end());
            for (int sz = g.size(), j = 0; j < sz; j++)
                if (find(g[j].u) != find(g[j].v))
                    fa[find(g[j].u)] = find(g[j].v), ans += g[j].w * 2;
            du[s]--, du[i]--;
            printf("%lld ", ans);
        }
    }
}
int main()
{
    FGF::work();
    return 0;
}
