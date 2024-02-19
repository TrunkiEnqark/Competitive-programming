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

const int N = 1e6 + 6;

int n, a[N], L[N], R[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    L[0] = INT_MAX;
    R[n + 1] = INT_MIN;

    for(int i = 1; i <= n; ++i) L[i] = min(L[i - 1], a[i]);
    for(int i = n; i > 0; --i)  R[i] = max(R[i + 1], a[i]);

    int res = 0;
    for(int i = 1; i <= n; ++i) res = max(res, R[i + 1] - L[i]);
    cout << res;

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/4631