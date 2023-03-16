#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <cstdlib>

using namespace std;
const int MAXN = 400005; // 这里注意要开双倍空间，因为圆方树上点的个数可能到2n的数量
// n是原图中点的数量，start和target是两个服务器，nn是圆方树上点的数量
int n, start, target, nn, pre[MAXN], low[MAXN], dt;
// 分别是原图，和圆方树的邻接表
vector<int> adj[MAXN], adjT[MAXN];
stack<int> s;

void tarjan(int u, int father)
{
    pre[u] = low[u] = ++dt;
    s.push(u);
    for (int i = 0; i < adj[u].size(); ++i)
    {
        int v = adj[u][i];
        if (pre[v] == 0)
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= pre[u])
            {
                nn++; // 找到一个新的点双连通分量，新增一个方点
                while (true)
                {
                    int t = s.top();
                    s.pop();
                    adjT[nn].push_back(t); // 原图中的点到方点连边
                    adjT[t].push_back(nn);
                    if (t == v)
                        break; // 这里pop到v为止，u点保留在栈里面，因为割点可能被很多点双公用
                }
                adjT[u].push_back(nn); // u点也在这个点双里面，也像方点连边。
                adjT[nn].push_back(u);
            }
        }
        else if (v != father)
        {
            low[u] = min(low[u], pre[v]);
        }
    }
}

// u是当前访问到的点，ans是目前从根走下来的路径上的答案，father是u的父亲
void dfs(int u, int ans, int father)
{
    if (u == target)
    {
        // 如果走到target了
        if (ans == 0)
        {
            // ans还是0，说明路上没经过割点
            printf("No solution\n");
        }
        else
        {
            printf("%d\n", ans);
        }
        exit(0);
    }
    if (u != start && adjT[u].size() > 1 && u <= n)
    {
        // 遇到非叶子的圆点，说明是割点
        if (ans == 0)
        {
            ans = u;
        }
        else
        {
            ans = min(ans, u);
        }
    }
    for (int i = 0; i < adjT[u].size(); ++i)
    {
        int v = adjT[u][i];
        if (v == father)
            continue;
        dfs(v, ans, u);
    }
}

int main()
{
    scanf("%d", &n);
    int u, v;
    while (scanf("%d%d", &u, &v))
    {
        if (u == 0 && v == 0)
            break;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    scanf("%d%d", &start, &target);
    nn = n;           // 最开始的时候，圆方树里面点的个数等于圆点个数
    tarjan(start, 0); // 从其中一个服务器开始跑一遍tarjan
    if (pre[target] == 0)
    {
        // 从起点到终点不连通
        printf("No solution\n");
        return 0;
    }
    // 这时候以start为根，在圆方树上dfs找target，沿途记录经过的最小的割点编号
    dfs(start, 0, 0);
    return 0;
}
