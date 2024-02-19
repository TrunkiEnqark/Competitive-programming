#include <bits/stdc++.h>

#define NAME        ""

#define ILTQ				 	int main()
#define ll          			long long
#define ii         		  		pair<int, int>
#define ld          			long double
#define fi          			first
#define se          			second
#define endl        			'\n'
#define pb          			push_back

#define OK          			cout << "ok\n";
#define all(a)      			a.begin(), a.end()
#define rall(a)     			a.rbegin(), a.rend()

using namespace std;

const int MOD = 1e9 + 7;
const int base = 29;
const int N = 1e5 + 5;

int n, q, a[N];
ii seg[N*2];

void down(int id, int l, int r) {
    int mid = (l + r) >> 1;
    int &t = seg[id].se;

    seg[id*2].fi = (mid - l + 1) - seg[id*2].fi;
    seg[id*2].se ^= 1;

    seg[id*2 + 1].fi = (r - mid) - seg[id*2 + 1].fi;
    seg[id*1 + 1].se ^= 1;
    
    t = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    if(l > r || l > v || r < u) return;

    if(u <= l && r <= v) {
        seg[id].fi = (r - l + 1) - seg[id].fi;
        seg[id].se ^= val;
        return;
    }

    int mid = (l + r) >> 1;
    down(id, l, r);
    update(id*2, l, mid, u, v, val);
    update(id*2, mid + 1, r, u, v, val);
    seg[id].fi = seg[id*2].fi + seg[id*2 + 1].fi;
}

int get(int id, int l, int r, int u, int v) {
    if(l > r || l > v || r < u) return 0;

    if(u <= l && r <= v) return seg[id].fi;

    int mid = (l + r) >> 1;
    down(id, l, r);
    return get(id*2, l, mid, u, v) + get(id*2 + 1, mid + 1, r, u, v);
}

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        update(1, 1, n + 1, i, n + 1, a[i]%2);
    }

    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int k, val;
            cin >> k >> val;
            a[k] = val;
            if(a[k]%2 == val%2) continue;
            update(1, 1, n + 1, k + 1, n + 1, 1);          
        } else {
            int l, r;
            cin >> l >> r;
            ll cnt0 = get(1, 1, n + 1, l, r + 1);
            ll cnt1 = r - l + 2 - cnt0;
            cout << cnt0 * (cnt0 - 1) / 2 + cnt1 * (cnt1 - 1) / 2 << endl;
        }
    }

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh