#include <bits/stdc++.h>

#define NAME        "sseq"

#define ILTQ				 	main()
#define ll          			long long
#define int                     ll
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
const int N = 1e5 + 6;

struct SegmentTree {
    int val, lazy;
} seg[4000006];

int n;
map<ii, int> mp;
pair<ii, int> a[N];

void build(int id, int l, int r) {
    if(mp.count({l, r})) {
        seg[id].val = mp[{l, r}];
        return;
    }

    int mid = (l + r) >> 1;
    build(id*2, l, mid);
    build(id*2 + 1, mid + 1, r);
    seg[id].val = max(seg[id*2].val, seg[id*2 + 1].val);
}

void down(int id) {
    int tmp = seg[id].lazy;

    seg[id*2].val += tmp;
    seg[id*2 + 1].val += tmp;

    seg[id*2].lazy += tmp;
    seg[id*2 + 1].lazy += tmp;

    seg[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, int w) {
    if(l > v || r < u || l > r) return;

    if(u <= l && r <= v) {
        seg[id].val += w;
        seg[id].lazy += w;
        return;
    }

    down(id);
    int mid = (l + r) >> 1;
    update(id*2, l, mid, u, v, w);
    update(id*2 + 1, mid + 1, r, u, v, w);
    seg[id].val = max(seg[id*2].val, seg[id*2 + 1].val);
}

ll get(int id, int l, int r, int u, int v) {
    if(l > v || r < u || l > r) return -1e9;

    if(u <= l && r <= v) return seg[id].val;

    down(id);
    int mid = (l + r) >> 1;
    return max(get(id*2, l, mid, u, v), get(id*2 + 1, mid + 1, r, u, v));
}

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    int L = 1e9, R = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
        mp[a[i].fi] = a[i].se;
        L = min(L, a[i].fi.fi);
        R = max(R, a[i].fi.se);
    }   

    // for(int i = 1; i <= n; ++i) update(1, 1, R, a[i].fi.fi, a[i].fi.se, a[i].se); 

    sort(a + 1, a + n + 1, [] (const pair<ii, int> &a, const pair<ii, int> &b) { return a.fi.se < b.fi.se; });

    ll res = 0;
    for(int i = 1; i <= n; ++i) {
        int l = a[i].fi.fi, r = a[i].fi.se, w = a[i].se;
        // cout << l << ' ' << r << endl;
        update(1, 0, 1e6, 0, l - 1, w);
        res = max(res, get(1, 0, 1e6, 0, r - 1));
    }

    cout << res;

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh