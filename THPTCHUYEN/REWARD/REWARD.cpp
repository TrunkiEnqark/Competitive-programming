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

const int N = 1e5 + 5;
const int INF = 1e9;

int n;
ll dp[N], a[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    ll ans = 0;
    for(int i = 1; i <= n; ++i) cin >> a[i], ans += a[i];
    // memset(dp, INF, sizeof(dp));
    for(int i = 1; i <= n + 1; ++i) dp[i] = INF;
    dp[0] = 0;
    for(int i = 1; i <= n + 1; ++i)
        dp[i] = min({dp[i], dp[max(0, i - 3)] + a[i], dp[max(0, i - 2)] + a[i], dp[max(0, i - 1)] + a[i]});
    cout << ans - dp[n + 1];

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/4663