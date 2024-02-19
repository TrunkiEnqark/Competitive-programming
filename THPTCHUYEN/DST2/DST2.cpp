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

int n, m;
vector<int> a[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m;
    for(int x, y; m--; ) {
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }

    ll ans = 0;
    for(int i = 1; i <= n; ++i) 
        for(int j = 0; j < a[i].size(); ++j) ans += a[a[i][j]].size() - 1;
    cout << ans / 2;

    return 0;
}