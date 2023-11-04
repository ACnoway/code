#include <bits/stdc++.h>

#define For(i, l, r) for (register int i = (l), i##end = int(r); i <= i##end; ++i)
#define Fordown(i, r, l) for (register int i = (r), i##end = (int)(l); i >= i##end; --i)
#define Rep(i, r) for (register int i = (0), i##end = int(r); i < i##end; ++i)
#define Set(a, v) memset(a, v, sizeof(a))
#define Cpy(a, b) memcpy(a, b, sizeof(a))
#define debug(x) cout << #x << ": " << (x) << endl

using namespace std;

typedef long long ll;

template<typename T> inline bool chkmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, T b) { return b > a ? a = b, 1 : 0; }

inline int read() {
	int x(0), sgn(1); char ch(getchar());
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') sgn = -1;
	for (; isdigit(ch); ch = getchar()) x = (x * 10) + (ch ^ 48);
	return x * sgn;
}

void File() {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
}

const int N = 41;

char S[N], T[N];

int n, m, L; ll val[N], base[N], fail[N];

void Get_Fail() {
	For (i, 2, L) {
		int j = fail[i - 1];
		while (j && S[j + 1] != S[i]) j = fail[j];
		fail[i] = j + (S[j + 1] == S[i]);
	}
}

int R, r; ll ans, aft[N];

void SolveSmallR() {
	static ll tmp[N], len = -1;
	Rep (i, m) if (base[i]) tmp[++ len] = base[i];
	Rep (i, 1 << R) {
		ll cur = 0, k = 0; 
		Rep (j, R) if (i >> j & 1) cur ^= tmp[j];
		Rep (j, m) T[j + 1] = (cur >> (m - 1 - j) & 1) + '0';
		For (j, 1, m) {
			while (k && T[j] != S[k + 1]) k = fail[k];
			if ((k += T[j] == S[k + 1]) == L) break;
		}
		if (k == L) ++ ans;
	}
	ans <<= n - R;
}

ll dp[2][N][1 << 17];

void SolveBigR() {
	ans = 0;
	Rep (i, m) if (base[i]) Rep (j, m) if (!base[j])
		aft[i] = aft[i] << 1 | (base[i] >> j & 1);

	dp[m & 1][0][0] = 1; r = m - R;

	int tot = 0;
	Fordown (i, m - 1, 0) {
		int cur = i & 1; if (base[i]) ++ tot;
		Rep (j, L) Rep (k, 1 << r) if (dp[cur ^ 1][j][k]) {
			if (base[i]) {
				Rep (c, 2) {
					int t = j; while (t && (S[t + 1] ^ '0') != c) t = fail[t];
					if ((t += ((S[t + 1] ^ '0') == c)) == L) ans += dp[cur ^ 1][j][k] << (n - tot);
					else dp[cur][t][k ^ (c * aft[i])] += dp[cur ^ 1][j][k];
				}
			} else {
				int now = k >> (m - 1 - i - tot) & 1, t = j;
				while (t && (S[t + 1] ^ '0') != now) t = fail[t];
				if ((t += ((S[t + 1] ^ '0') == now)) == L) ans += dp[cur ^ 1][j][k] << (n - tot);
				else dp[cur][t][k] += dp[cur ^ 1][j][k];
			}
			dp[cur ^  1][j][k] = 0;
		}
	}
}

int main () {

	File();

	n = read(); m = read();
	For (i, 1, n) {
		scanf ("%s", T + 1);
		For (j, 1, m) val[i] = val[i] << 1 | (T[j] ^ '0');
	}
	L = read(); scanf ("%s", S + 1);

	Get_Fail();

	For (i, 1, n) Fordown (j, m - 1, 0)
		if (val[i] >> j & 1) {
			if (!base[j]) {
				++ R; base[j] = val[i]; break;
			} else val[i] ^= base[j];
		}

	For (i, 0, m) Rep (j, i) 
		if (base[i] >> j & 1) base[i] ^= base[j];

	R <= 23 ? SolveSmallR() : SolveBigR();

	printf ("%lld\n", ans);

	return 0;

}
