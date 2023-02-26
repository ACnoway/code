#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000;
vector<int> G[MAXN+1]; // 树的邻接表表示
int color[MAXN+1]; // 节点颜色
int count[MAXN+1][MAXN+1]; // count[u][c]表示从根节点到节点u路径上颜色为c的个数
long long ans = 0; // 答案

void dfs(int u, int fa) {
    count[u][color[u]]++; // 将节点u的颜色计数加入count[u]
    for (int v : G[u]) {
        if (v == fa) continue;
        dfs(v, u);
        for (int c = 1; c <= MAXN; c++) {
            count[u][c] += count[v][c]; // 更新count[u]
        }
    }
    for (int v : G[u]) {
        if (v == fa) continue;
        for (int c = 1; c <= MAXN; c++) {
            ans += (long long) count[v][c] * count[u][c]; // 计算点对数目的贡献
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
