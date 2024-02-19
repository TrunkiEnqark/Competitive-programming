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

const int M = 1e5 + 5;

int m, n, dp[M][15];
char a[M][15], res[M][15];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m;
    memset(res, '.', sizeof(res));
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if(a[i][j] == '#') res[i][j] = '#';
        }
    
    memset(dp, 0, sizeof(dp));
    for(int j = 1; j <= m; ++j) {
        int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            if(a[i][j] == 'a') ++cnt;
            if(a[i][j] == '#') {
                dp[i][j] = cnt;
                cnt = 0;
            }
            if(i == n && a[i][j] != '#') dp[i][j] = cnt;
        }
    }

    // for(int i = 1; i <= n; ++i)
        // for(int j = 1; j <= m; ++j) cout << dp[i][j] << " \n"[j == m];
    
    for(int j = 1; j <= m; ++j) {
        for(int i = n; i > 0; --i) {
            if(dp[i][j] > 0) {
                int k, r = dp[i][j];
                if(i == n && a[i][j] != '#') ++i;
                // res[i][j] = '#';
                for(k = i - 1; r--; --k) res[k][j] = 'a';
                i = k + 1;
            }
        }
    }
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) cout << res[i][j]; 
        cout << '\n';
    }

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/4611