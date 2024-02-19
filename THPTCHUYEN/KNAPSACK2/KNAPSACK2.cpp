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

const int N = 5e3 + 3, W = 1e4 + 4;

int n, m, v[N], w[W];
int dp[N][W];
// vector<vector<int> > dp(N, vector<int> (W, 0));

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> w[i] >> v[i];

    for(int i = 1; i <= n; ++i)
        for(int j = 0; j <= m; ++j) {
            dp[i][j] = dp[i - 1][j];
            if(j >= w[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
        }
    cout << dp[n][m];
    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9871