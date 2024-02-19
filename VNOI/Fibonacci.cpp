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

// const int MOD = 1e9 + 7;
const int base = 29;
const int N = 1e6 + 6;

int f[3 * N], save[N];
int n;
ll x, MOD;

int Findlim() {
    f[1] = f[2] = 1;
    int i = 3;
    while(1 + 1 == 2) {
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
        if(f[i] == 1 && f[i - 1] == 1) return i - 2;
        i++;
    }
}

void solve() {
    cin >> n >> x >> MOD;
    memset(save, 0, sizeof save);

    int lim = Findlim();
    // cout << lim << endl;

    // for(int i = 1; i <= 10; ++i) cout << f[i] << " \n"[i == 10];

    int sum = 0;
    save[0] = -1;
    for(int i = 0; i < n; ++i) {
        sum = (sum + f[(x + i) % lim]) % MOD;
        // cout << sum << ' ';
        if(save[sum] != 0) {
            // cout << sum << endl;
            ll l = save[sum] + x + 1;
            ll r = x + i;
            cout << r - l + 1 << ' ';
            for(; l <= r; ++l) cout << l << ' ';
            cout << endl;
            return;
        }
        save[sum] = i;
    }
}

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh