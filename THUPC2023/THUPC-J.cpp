#include<bits/stdc++.h>
#define debug_(x) cerr << #x << " = " << x << ' '
#define debug(x) cerr << #x << " = " << x << '\n'

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    const ll P = 998244353;
    
    auto qpow = [&](ll a, ll n) {
        ll res = 1;
        while (n) {
            if (n & 1) res = res * a % P;
            a = a * a % P;
            n >>= 1;
        }
        return res;
    };
    
    auto inv = [&](ll x) {
        return qpow(x, P - 2);
    };
    
    int n;
    cin >> n;
    vector<ll> mi(n + 1), w(n + 1);
    mi[0] = 1;
    for (int i = 1; i <= n; i++) mi[i] = mi[i - 1] * 2 % P;
    for (int i = 0; i <= n; i++) {
        if (i == 0) w[i] = 1;
        else if(i == 1) w[i] = 2;
        else w[i] = (i + 3) * mi[i - 2] % P;
    }
    ll s = accumulate(w.begin(), w.end(), 0ll) % P;
    ll invs = inv(s), invn = inv(n + 2);
    for (int i = 0; i <= n; i++) {
        if (i == 0) cout << 2 * invn % P << " \n"[i == n];
        else cout << 1 * invn % P << " \n"[i == n];
    }
    for (int i = 0; i <= n; i++) {
        cout << w[i] * invs % P << " \n"[i == n];
    }
    
    return 0;
}