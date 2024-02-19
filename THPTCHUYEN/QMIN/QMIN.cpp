#include <bits/stdc++.h>

#define NAME "txt"

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

int n, q, a[N], seg[N<<2];

void build(int id, int l, int r) {
    if(l > r) return;

    if(l == r) {
        seg[id] = a[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(2*id, l, mid);
    build(2*id + 1, mid + 1, r);
    seg[id] = min(seg[id*2], seg[id*2 + 1]);
}

int query(int id, int l, int r, int u, int v) {
    if(l > r || v < l || r < u) return INT_MAX;

    if(l >= u && r <= v) return seg[id];

    int mid = (l + r) >> 1;
    return min(query(id*2, l, mid, u, v), query(id*2 + 1, mid + 1, r, u, v));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);

    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << query(1, 1, n, l, r) << endl;
    }

    return 0;
}