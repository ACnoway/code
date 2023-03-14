#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
struct Segment
{
    int l, r;
} a[maxn];
int n, m, cnt, q, k, d[maxn];
int vis_node[maxn], vis[maxn], color[maxn], degree[maxn]; // 标记一下每条边的颜色
vector<int> ji, c;
struct node
{
    int to, id;
};
vector<node> edge[maxn];
void dfs(int u)
{
    vis_node[u] = 1; // 表示他们的
    for (int i = d[u]; i < edge[u].size(); i = d[u])
    {
        d[u] = i + 1;
        if (vis[edge[u][i].id])
            continue;
        vis[edge[u][i].id] = 1;
        color[edge[u][i].id] = u < edge[u][i].to;
        dfs(edge[u][i].to);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].l >> a[i].r;
        a[i].r++;
        c.push_back(a[i].l), c.push_back(a[i].r);
    }
    sort(c.begin(), c.end());
    auto et = unique(c.begin(), c.end());
    for (int i = 1; i <= n; ++i)
    { // 表示这几条边
        a[i].l = lower_bound(c.begin(), et, a[i].l) - c.begin() + 1;
        a[i].r = lower_bound(c.begin(), et, a[i].r) - c.begin() + 1;
        edge[a[i].l].push_back((node){a[i].r, i});
        edge[a[i].r].push_back((node){a[i].l, i});
        degree[a[i].l]++, degree[a[i].r]++; // 表示加入度数
    }
    for (int i = 1; i <= 2 * n; ++i)
    {
        if (degree[i] & 1)
            ji.push_back(i);
    }
    int p = 0, cnt = n;
    for (int i = 0; i < ji.size(); i++)
    {
        if (!p)
            p = ji[i];
        else
        {
            cnt++;
            edge[p].push_back((node){ji[i], cnt});
            edge[ji[i]].push_back((node){p, cnt});
            p = 0;
        }
    }
    for (int i = 1; i <= 2 * n; ++i)
    {
        if (!degree[i])
            continue;
        if (!vis_node[i])
            dfs(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << color[i] << " ";
    }
    return 0;
}