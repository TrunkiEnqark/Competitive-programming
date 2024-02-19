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

const int N = 1e3 + 3;

int n, m, w[N], v[N];
ll dp[N][N];

void maximize(int &a, int b) {
    a = max(a, b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> w[i] >> v[i];

    // dp[0][0] = 0;
    memset(dp, 0, sizeof(dp));
    // ll res = LLONG_MIN;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j <= m; ++j) {
            dp[i][j] = dp[i - 1][j];
            if(j >= w[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    cout << dp[n][m];

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/4683