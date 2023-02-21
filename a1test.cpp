#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1000005;

char a[MAXN], b[MAXN];
int n, q[MAXN], p[26], cnt[26];

void solve() {
    cin >> n;
    cin >> a >> b;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        p[b[i] - 'A'] = i;
        cnt[a[i] - 'A']++;
    }
    for (int i = 1; i < 26; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; i++) {
        q[i] = cnt[a[i] - 'A'] - 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j = p[a[i] - 'A'];
        while (q[j] != i) {
            swap(a[j], a[j - 1]);
            swap(q[j], q[j - 1]);
            ans++;
            j--;
            if (j <= 0) break;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
