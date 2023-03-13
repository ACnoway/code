#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
typedef long long ll;
int v[N];
int x[N];
int ct;
int al[N];
int col[N];
int n;
int lstu[N];
int lstv[N];
inline void add(int u, int V)
{
    v[++ct] = V;
    x[ct] = al[u];
    al[u] = ct;
}
inline void dfs(int u, int tw)
{
    col[u] = tw;
    for (int i = al[u]; i; i = x[i])
        if (col[v[i]] == -1)
            dfs(v[i], tw ^ 1);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        col[i] = -1;
    for (int i = 1, x, y; i <= n; i++)
    {
        scanf("%d%d", &x, &y);
        if (lstu[x])
        {
            add(lstu[x], i), add(i, lstu[x]), lstu[x] = 0;
        }
        else
            lstu[x] = i;
        if (lstv[y])
        {
            add(lstv[y], i), add(i, lstv[y]), lstv[y] = 0;
        }
        else
            lstv[y] = i;
    }
    for (int i = 1; i <= n; i++)
        if (col[i] == -1)
            dfs(i, 0);
    for (int i = 1; i <= n; i++)
        putchar((col[i]) ? 'r' : 'b');
    return 0;
}
