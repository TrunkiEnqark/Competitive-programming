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
const int MOD = 1e6 + 3;

int n;
char a[N][N];
bool ok[N][N];
int dp[N][N];
string s;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) cin >> a[i][j];
    cin >> s;
    if(a[0][0] != s[0] || a[n - 1][n - 1] != s[2*n - 2]) {
        cout << 0;
        return 0;
    }

    memset(ok, false, sizeof(ok));
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    ok[0][0] = true;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) if(i > 0 || j > 0) {
            if(a[i][j] == s[i + j]) {
                // cout << "?";
                ok[i][j] = true;
                if(ok[i - 1][j]) dp[i][j] = (dp[i][j] + dp[i - 1][j])%MOD;
                if(ok[i][j - 1]) dp[i][j] = (dp[i][j] + dp[i][j - 1])%MOD;
            }
        }
    // for(int i = 0; i < n; ++i)
        // for(int j = 0; j < n; ++j) cout << dp[i][j] << " \n"[j == n - 1];

    cout << dp[n - 1][n - 1];

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/10960