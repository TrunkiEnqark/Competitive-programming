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

int n, k, a[N], t[N];

bool ok(int x) {
    return ((int) sqrt(x) * sqrt(x) == x);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        t[i] = k - a[i];
        if(!ok(t[i]) || a[i] < 0) t[i] = -1;
    }

    ll res = 0;
    for(int i = 1; i <= n; ++i) {
        if(t[i] != -1) for(int j = i; j <= n; ++j) if(t[i] == a[j] * a[j]) ++res;
    }
    cout << res;

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/4511