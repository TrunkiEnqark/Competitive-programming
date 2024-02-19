#include <bits/stdc++.h>

#define NAME ""

#define fo(i, a, b) for(int i = a; i <= b; ++i)
#define all(a)		a.begin(), a.end()

#define int         long long
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

const int N = 1005;

int n, m, a[N][N], s[2][N], dp[N], tmp[N], ok[2][N][N];

int sum(int id, int i, int j) { return s[id][j] - s[id][i - 1]; }

void cal(int id1, int id2, int len, int n) {
    if(len > n) return;

    for(int i = 1; i <= n - len + 1; ++i) {
        int j = i + len - 1;
        for(int k = i; k < j; ++k)  
            if(ok[id2][i][k] && ok[id2][k + 1][j] && sum(id1, i, k) == sum(id1, k + 1, j)) { ok[id2][i][j] = true; break; }
    }

    cal(id1, id2, len + 1, n);
}

int F(int id, int n) {
    // memset(dp, 1e9, sizeof dp);
    for(int i = 1; i < N; ++i) dp[i] = 1e9;
    dp[0] = 0;
    for(int i = 1; i <= n; ++i) 
        for(int j = 0; j < i; ++j) 
            if(ok[id][j + 1][i]) dp[i] = min(dp[i], dp[j] + 1);
    
    for(int i = 1; i <= n; ++i) cout << dp[i] << " \n"[i == n];

    return dp[n];
}

main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m;

    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= m; ++j) cin >> a[i][j];

    memset(s, 0, sizeof s);
    // memset(s2, 0, sizeof s2);

    tmp[0] = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) 
            tmp[i] += a[i][j];
    
    for(int i = 1; i <= n; ++i) s[0][i] = s[0][i - 1] + tmp[i];

    memset(tmp, 0, sizeof tmp);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) 
            tmp[j] += a[i][j];
    
    for(int i = 1; i <= m; ++i) s[1][i] = s[1][i - 1] + tmp[i];

    for(int i = 1; i <= max(n, m); ++i) ok[0][i][i] = ok[1][i][i] = true;

    cal(0, 0, 0, n);
    cal(1, 1, 0, m);

    cout << F(1, m) << '\n' << F(0, n);

    return 0;
}

//https://oj.vnoi.info/problem/voi21_rmat
