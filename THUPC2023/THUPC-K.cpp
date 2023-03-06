#include<bits/stdc++.h>
#define debug_(x) cerr << #x << " = " << x << ' '
#define debug(x) cerr << #x << " = " << x << '\n'

using namespace std;

typedef long long ll;

const int N = (int)1e5;

ll s[(N + 2) << 2], tag[(N + 2) << 2];

void pd(int i, int l, int r) {
    int mid = (l + r) >> 1;
    s[i << 1] += tag[i] * (mid - l + 1);
    s[i << 1 | 1] += tag[i] * (r - mid);
    tag[i << 1] += tag[i];
    tag[i << 1 | 1] += tag[i];
    tag[i] = 0;
}

void pu(int i) {
    s[i] = s[i << 1] + s[i << 1 | 1];
}

void add(int i, int tl, int tr, int l, int r) {
    // cerr << i << ' ' << tl << ' ' << tr << ' ' << l << ' ' << r << "-\n";
    if (tl >= l && tr <= r) {
        s[i] += tr - tl + 1;
        tag[i] += 1;
        return;
    }
    pd(i, tl, tr);
    int mid = (tl + tr) >> 1;
    if (l <= mid) add(i << 1, tl, mid, l, r);
    if (mid + 1 <= r) add(i << 1 | 1, mid + 1, tr, l, r);
    pu(i);
}

ll get(int i, int tl, int tr, int l, int r) {
    if (tl >= l && tr <= r) {
        return s[i];
    }
    pd(i, tl, tr);
    int mid = (tl + tr) >> 1;
    ll res = 0;
    if (l <= mid) res += get(i << 1, tl, mid, l, r);
    if (mid + 1 <= r) res += get(i << 1 | 1, mid + 1, tr, l, r);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    int n;
    cin >> n;
    vector<int> a(n), cnt(N + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<array<int, 2>>> query(n);
    int pre = 0;
    for (int i = n - 1; i >= 0; ) {
        query[i].push_back({a[i], 1});
        query[i].push_back({pre, -1});
        pre = a[i];
        int j = i;
        while (j >= 0 && a[j] <= a[i]) j--;
        i = j;
    }
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        add(1, 0, N, 1, a[i]);
        for (auto [num, sign] : query[i]) {
            ans += (ll)sign * (i + 1) * get(1, 0, N, 1, num);
        }
    }
    cout << ans << '\n';
    
    return 0;
}