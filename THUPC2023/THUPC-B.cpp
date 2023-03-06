#include<bits/stdc++.h>
#define debug_(x) cerr << #x << " = " << x << ' '
#define debug(x) cerr << #x << " = " << x << '\n'

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> w(n);
    for (auto &it : w) cin >> it;
    
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int fa;
        cin >> fa;
        fa--;
        g[fa].push_back(i);
    }
    
    vector<int> dep(n), sz(n);
    function<void(int)> dfs = [&](int u) {
        sz[u] = 1;
        for (auto v : g[u]) {
            dep[v] = dep[u] + 1;
            dfs(v);
            sz[u] += sz[v];
        }
        w[u] = -w[u] + sz[u] - 1 - dep[u];
    };
    dfs(0);
    
    sort(w.begin(), w.end(), greater<int>());
    ll ans = 0;
    for (int i = 0; i < n; i += 2) {
        ans += w[i];
    }
    cout << ans << '\n';
    
    return 0;
}