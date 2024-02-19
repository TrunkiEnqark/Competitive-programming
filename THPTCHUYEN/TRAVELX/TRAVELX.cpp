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

int n, x[N];
ll s[N], a[N];

void subtask() {
    ll res = 0;
    sort(a+1, a+n+1);
    s[0] = 0;
    for(int i = 1; i <= n; ++i) s[i] = (ll) s[i - 1] + a[i];
    for(int i = 1; i <= n; ++i) {
        res += (ll) a[i];
        res += (ll) abs((ll) s[n] - s[i] - a[i] * (n - i))*2ll;
        // for(int j = i + 1; j <= n; ++j) res += abs(a[i] - a[j])*2;
    }

    ll r2 = n;
    ll g = gcd(res, r2);
    cout << (ll) res/g << ' ' << (ll) r2/g;
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    subtask();
    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/6800