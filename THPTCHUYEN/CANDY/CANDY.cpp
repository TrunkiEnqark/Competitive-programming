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

const int N = 2e5 + 5;

int n;
ll a[N], dp[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    dp[0] = 0;
    for(int i = 1; i <= n; ++i) cin >> a[i], dp[i] = dp[i - 1] + a[i];

    ll r = INT_MAX;
    for(int k = 1; k <= n; ++k) if(abs(dp[k] - (dp[n] - dp[k])) < r) r = abs(dp[k] - (dp[n] - dp[k]));
    cout << r;

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/4662