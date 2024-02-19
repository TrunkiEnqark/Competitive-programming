#include <bits/stdc++.h>

#define NAME ""

#define fo(i, a, b) for(int i = a; i <= b; ++i)
#define all(a)		a.begin(), a.end()

#define pb 			push_back
#define endl		'\n'
#define ll 			long long
#define ii 			pair<int, int>
#define x			first
#define y 			second

using namespace std;

ll gcd(ll a, ll b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

const int N = 1e5 + 5;

int n;
ll x[N], y[N];

ll operator - (const ii &a, const ii &b) {
    return (abs(a.x - b.x) + abs(a.y - b.y));
}

ll calc(ll x[], int n) {
    sort(x, x + n);

    ll res = 0, sum = 0;
    for(int i = 0; i < n; ++i) {
        res += (ll) ((ll) x[i] * i - sum);
        sum += (ll) x[i];
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    cout << (ll) calc(x, n) + calc(y, n);

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/6910