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

int n, a[1005], dp[1005];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], dp[i] = 1;

    int res = 0;
    for(int i = 2; i <= n; ++i) {
        // dp[i] = dp[i - 1];
        for(int j = 1; j < i; ++j) 
            if(a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
    }
    cout << res;

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9868