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

bool ok(ll x) {
    ll tmp = sqrt(x);
    return tmp*tmp == x;
}

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    ll k;
    cin >> k;
    int res = 0;
    for(ll i = 1; i * i <= k; ++i) {
        if(ok(k - i*i)) res++;
    }
    cout << res;

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh