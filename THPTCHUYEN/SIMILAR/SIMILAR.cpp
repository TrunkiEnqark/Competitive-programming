#include <bits/stdc++.h>

#define NAME "txt"

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

int n, a[N], b[N], dp[N][N], lf[N], rt[N];

void sub1() {
    int res = 0;
    
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            reverse(b + i + 1, b + j + 1);
            
            int cnt = 0;
            for(int k = 1; k <= n; ++k) cnt += (a[k] == b[k]);
            res = max(res, cnt);

            reverse(b + i + 1, b + j + 1);
        }
    }
    cout << res << endl;
    exit(0);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
    
    if(n <= 400) sub1();

    int ans = 0;
    for(int i = 1; i <= n; ++i) if(a[i] == b[i]) ++ans;

    // lf[0] = rt[n + 1] = 0;
    memset(lf, 0, sizeof(lf));
    memset(rt, 0, sizeof(rt));
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; ++i) {
        lf[i] = lf[i - 1];
        if(a[i] == b[i]) ++lf[i];
    }

    for(int j = n; j > 0; --j) {
        rt[j] = rt[j + 1];
        if(a[j] == b[j]) ++rt[j];
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = n; j > 0; --j) {  
            dp[i][j] = dp[i - 1][j + 1];
            if(a[i] == b[j]) dp[i][j] = dp[i - 1][j + 1] + 1;
        }
    }

    // for(int i = 1; i <= n; ++i) 
        // for(int j = 1; j <= n; ++j) cout << dp[i][j] << " \n"[j == n];
    
    int res = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            res = max({res, dp[i][j] + lf[min(i, j) - 1] + rt[max(i, j) + 1], lf[i] + rt[i + 1]});
        }
    }
// djt con me cai test lon
// du ma cay vai
    cout << min(n, max({ans, res, 0}));
    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/10962