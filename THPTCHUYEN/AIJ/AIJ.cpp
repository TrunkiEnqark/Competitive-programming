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
ll ma = LLONG_MIN, mi = LLONG_MAX;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int x, i = 1; i <= n; ++i) {
        cin >> x;
        // a[i] = (ll) a[i] * a[i];
        ma = max(ma, 1ll * x * x);
        mi = min(mi, 1ll * x * x);
    }
    cout << ma - mi;

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/8456