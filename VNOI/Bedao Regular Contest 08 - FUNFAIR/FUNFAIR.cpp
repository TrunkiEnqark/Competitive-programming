#include <bits/stdc++.h>

#define NAME        ""

// #define int         long long
#define ll          long long
#define ii          pair<int, int>
#define ld          long double
#define fi          first
#define se          second
#define endl        '\n'
#define pb          push_back

#define OK          cout << "ok\n";
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

using namespace std;

const int MOD = 1e9 + 7;
const int base = 29;
const int N = 1e6 + 6;

int n, x, y, a[N];
ll f[N];
vector<ii> d;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> x >> y;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i]; 
        f[i] = f[i - 1] + a[i];
    }
    a[0] = a[n + 1] = INT_MIN;

    int l = -1, r = -1;
    for(int i = 1; i <= n + 1; ++i) {
        if(a[i] >= x && a[i - 1] < x) {
            l = i;
        } 
        if(a[i] < x && a[i - 1] >= x) {
            r = i - 1;
        }
        if(l > 0 && r > 0) {
            d.pb({l, r});
            l = -1;
            r = -1;
        }
    }

    // cout << f[7] - f[0] << endl;

    ll ans = LLONG_MIN;
    int L = -1, R = -1;
    for(auto it : d) {
        int l = it.fi, r = it.se;
        // cout << l << ' ' << r << endl;
        int x = l - 1;
        bool ok = false;
        for(int i = l, j = l; i <= r; ++i) {
            if(a[i] <= y) {
                for(; j <= i; ++j) {
                    if(f[x] > f[j - 1]) x = j - 1;
                }
                ok = true;
            }

            if(ok && x + 1 <= i && ans < f[i] - f[x]) {
                ans = f[i] - f[x];
                L = x + 1;
                R = i;
            }
        }
    }

    cout << ans << endl << L << ' ' << R;

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh
