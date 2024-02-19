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

const int N = 1e3 + 5;

int n, m, a[N], b[N], dp[N][N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= m; ++i) cin >> b[i];

    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; ++i) if(a[i] == b[1]) dp[i][1] = 1; else dp[i][1] = dp[i - 1][1];
    for(int j = 1; j <= m; ++j) if(a[1] == b[j]) dp[1][j] = 1; else dp[1][j] = dp[1][j - 1];
    
    // dp[1][1] = (a[1] == b[1]);
    int res = 1;
    for(int i = 2; i <= n; ++i) {
        for(int j = 2; j <= m; ++j) {
            dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            if(a[i] == b[j]) dp[i][j] = max(dp[i][j], dp[i - 2][j - 2] + 1);
            // res = max(res, dp[i][j]);
        }
    }
    cout << max(res, dp[n][m]);

    return 0;   
}

//http://thptchuyen.ntucoder.net/Problem/Details/6849