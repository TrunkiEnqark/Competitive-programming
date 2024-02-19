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

int n, m, a[22][22], dp[22][22];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) cin >> a[i][j];

    dp[1][1] = a[1][1];
    for(int i = 2; i <= n; ++i) dp[1][i] = dp[1][i - 1] + a[1][i];
    for(int i = 2; i <= m; ++i) dp[i][1] = dp[i - 1][1] + a[i][1];

    for(int i = 2; i <= n; ++i) 
        for(int j = 2; j <= m; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
        }
    cout << dp[n][m];
    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9760