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

int n, a[N], b[N], c[N], d1[N], d2[N], d3[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i] >> b[i] >> c[i];

    // d1[1] = a[1];
    // d2[1] = b[1];
    // d3[1] = c[1];
    // d1[2] = max(b[1], c[1]) + a[2];
    // d2[2] = max(a[1], c[1]) + b[2];
    // d3[2] = max(a[1], b[1]) + c[2];

    for(int i = 1; i <= n; ++i) {
        d1[i] = max(d2[i - 1], d3[i - 1]) + a[i];
        d2[i] = max(d1[i - 1], d3[i - 1]) + b[i];
        d3[i] = max(d1[i - 1], d2[i - 1]) + c[i];
    }
    cout << max({d1[n], d2[n], d3[n]});

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9924