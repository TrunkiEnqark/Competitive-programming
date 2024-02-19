#include <bits/stdc++.h>

#define NAME        "sseq"

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
const int N = 1e5 + 6;

int n, p[1000005];
pair<ii, int> a[N];
vector<int> lf;

void kadane() {
    for(int i = 1; i <= n; ++i) cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
    
    sort(a + 1, a + n + 1, [] (const pair<ii, int> &a, const pair<ii, int> &b) { return a.fi.fi < b.fi.fi; });

    int sum = 0, k = 0;

    ll s = 0, ans = 0;
    for(int i = 1; i <= n; ++i) {
        s = max(s + a[i].se, (ll) a[i].se);
        ans = max(ans, s);
    }
    cout << ans;
}

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    if(n > 3000) {
        kadane();
        return 0;
    }
    int L = 1e9, R = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].fi.se >> a[i].fi.fi >> a[i].se;
        lf.pb(a[i].fi.se);
        L = min(L, a[i].fi.se);
        R = max(R, a[i].fi.fi);
    }   

    sort(a + 1, a + n + 1, [] (const pair<ii, int> &a, const pair<ii, int> &b) { return a.fi.fi < b.fi.fi; });

    sort(all(lf));

    ll res = 0;
    for(auto l : lf) {
        ll sum = 0;
        for(int i = 1; i <= n; ++i) {
            if(a[i].fi.se >= l) {
                sum += a[i].se;
                if(a[i].fi.fi > a[i - 1].fi.fi) res = max(res, sum);
            }
        }
    }

    cout << res;

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh
