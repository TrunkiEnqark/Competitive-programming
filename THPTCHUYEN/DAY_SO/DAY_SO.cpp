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

int n;
ll a[N], dp[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    ll res = LLONG_MIN;
    for(int i = 1; i <= n; ++i) {
        // dp[i] = a[i];
        ll dpmax = LLONG_MIN;
        for(int j = 1; j < i - 1; ++j) dpmax = max(dpmax, dp[j]);
        dp[i] = (dpmax == LLONG_MIN ? 0 : dpmax) + a[i];
        res = max(res, dp[i]);
    }
    
    cout << res;

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9780