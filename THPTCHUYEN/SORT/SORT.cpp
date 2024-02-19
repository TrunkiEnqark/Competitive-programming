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

int n, ans[N], seg[N<<2], add[N<<2];
ii a[N];

void update(int id, int l, int r, int u, int v, ll val) {
	if(v < l || r < u || l > r) return;

	if(u <= l && r <= v) {
		add[id] += val;
		seg[id] += val;
		return;
	}

	int mid = (l + r) >> 1;
	update(id*2, l, mid, u, v, val);
	update(id*2+1, mid+1, r, u, v, val);

	seg[id] = max(seg[id*2], seg[id*2+1]) + add[id];
}

int get(int id, int l, int r, int u, int v) {
	if(v < l || r < u || l > r) {
		return INT_MIN;
	}

	if(u <= l && r <= v) {
		return seg[id];
	}

	int mid = (l + r) >> 1;
	return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v)) + add[id];
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i].fi, a[i].se = i;

    sort(a + 1, a + n + 1);

    int l = 1, r = n;
    while(l <= r) {
        int i = a[l].se + get(1, 1, n, a[l].se, a[l].se), j = a[r].se + get(1, 1, n, a[r].se, a[r].se);
        ans[l] = abs(l - i);
        ans[r] = abs(r - j - (i > j));
        
        // for(int x = 1; x < a[l].se; ++x) ++add[x];
        // for(int y = a[r].se + 1; y <= n; ++y) --add[y];
        update(1, 1, n, 1, a[l].se - 1, 1);
        update(1, 1, n, a[r].se + 1, n, -1);

        if(l != r) cout << ans[l] << ' ' << ans[r] << ' ';
            else cout << ans[l] << ' ';
        ++l, --r;
    }

    return 0;
}