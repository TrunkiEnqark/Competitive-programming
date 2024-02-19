#include <bits/stdc++.h>

#define NAME ""

#define fo(i, a, b) for(int i = a; i <= b; ++i)
#define all(a)		a.begin(), a.end()

#define pb 			push_back
#define endl		'\n'
#define ll 			long long
#define ii 			pair<int, int>
#define fi 			first
#define se 			second

using namespace std;

ll gcd(ll a, ll b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

const int MOD = 1e9 + 7;

struct matrix {
    ll c[15][15];
};

int m;
matrix a;
ll n;

matrix operator * (const matrix &a, const matrix &b) {
    matrix res;

    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= m; ++j) {
            res.c[i][j] = 0;
            for(int k = 1; k <= m; ++k) res.c[i][j] = (ll) (res.c[i][j] + (ll) (a.c[i][k] * b.c[k][j]) % MOD) % MOD;
        }

    return res;
}

matrix power(ll p) {
    if(p == 1) return a;
    matrix x = power(p >> 1);
    x = x * x;
    if(p&1) return x * a;
    return x;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= m; ++j) cin >> a.c[i][j];
    // cout << power(a, n);
    matrix ans = power(n);
    for(int i = 1; i <= m; ++i) 
        for(int j = 1; j <= m; ++j) cout << ans.c[i][j] << " \n"[j == m];

    return 0;
}