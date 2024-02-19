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

const int N = 1505;

int n, m, k, a[N][N], dp[N][N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) cin >> a[i][j];
    
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) 
            dp[i][j] = a[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
    
    int res = -1;

    for(int i = k; i <= n; ++i)
        for(int j = k; j <= m; ++j) res = max(res, dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k]);

    cout << res;

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9898