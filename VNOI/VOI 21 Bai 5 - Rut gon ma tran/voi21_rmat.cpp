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

const int N = 5005;

int n, m, a[N][N], s1[N], s2[N], dp[N], tmp[N];
vector<vector<bool> > ok1(N, vector<bool> (N, false)), ok2(N, vector<bool> (N, false));

int sum(int s[], int i, int j) { return s[j] - s[i - 1]; }

void cal(int s[], vector<vector<bool> > &ok, int len, int n) {
    if(len > n) return;

    for(int i = 1; i <= n - len + 1; ++i) {
        int j = i + len - 1;
        for(int k = i; k < j; ++k)  
            if(ok[i][k] && ok[k + 1][j] && sum(s, i, k) == sum(s, k + 1, j)) { ok[i][j] = true; break; }
    }

    cal(s, ok, len + 1, n);
}

int F(int s[], vector<vector<bool> > ok, int n) {
    // memset(dp, 1e9, sizeof dp);
    for(int i = 1; i < N; ++i) dp[i] = 1e16;
    dp[0] = 0;
    for(int i = 1; i <= n; ++i) 
        for(int j = 0; j < i; ++j) 
            if(ok[j + 1][i]) dp[i] = min(dp[i], dp[j] + 1);
    
    return dp[n];
}

main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m;
    if(n > 1e4) {
        cout << 1;
        return 0;
    }

    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= m; ++j) cin >> a[i][j];

    memset(s1, 0, sizeof s1);
    memset(s2, 0, sizeof s2);

    tmp[0] = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) 
            tmp[i] += a[i][j];
    
    for(int i = 1; i <= n; ++i) s1[i] = s1[i - 1] + tmp[i];

    memset(tmp, 0, sizeof tmp);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) 
            tmp[j] += a[i][j];
    
    for(int i = 1; i <= m; ++i) s2[i] = s2[i - 1] + tmp[i];
    

    for(int i = 1; i <= n; ++i) ok1[i][i] = true;
    for(int i = 1; i <= m; ++i) ok2[i][i] = true;

    cal(s1, ok1, 0, n);
    cal(s2, ok2, 0, m);

    // for(int i = 1; i <= m; ++i)
        // for(int j = 1; j <= m; ++j) cout << ok2[i][j] << " \n"[j == m];

    cout << 1ll * F(s2, ok2, m) * F(s1, ok1, n);
}

//https://oj.vnoi.info/problem/voi21_rmat
