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
const int N = 2e5 + 5;

int n, a[N];

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    // int n;
    cin >> n;
    // int a[n + 1];
    for(int i = 1; i <= n; ++i) cin >> a[i];

    ll ans = 0;
    for(int msk = 1; msk < (1 << n); ++msk) {
        int g = 0;
        bitset<8> tmp(msk);
        cout << tmp << ' ';
        for(int i = 1; i <= n; ++i) 
            if((msk >> (i - 1)) & 1) g = __gcd(g, a[i]);
        ans += g;
        ans %= MOD;
        cout << g << ' ' << ans << endl;
    }
    cout << ans % MOD;

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh