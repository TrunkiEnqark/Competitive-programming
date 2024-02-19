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

const int N = 1000005;

int n;
ll dp[N], a[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    dp[0] = 0ll;
    for(int i = 1; i <= n; ++i) cin >> a[i], dp[i] = dp[i - 1] + a[i];

    int ans = n;
    ll r = LLONG_MAX;
    for(int k = 1; k < n; ++k) {
        ll t1 = dp[k];
        ll t2 = dp[n] - t1;
        ll calc = (ll) abs(t1 - t2);
        // cout << calc << endl;
        if(calc == 0) {
            cout << k;
            return 0;
        }

        if(calc < r) {
            r = calc;
            ans = k;
        } 
    }
    // cout << dp[1] << ' ' << dp[n] - dp[1] << endl;
    cout << ans;

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9852