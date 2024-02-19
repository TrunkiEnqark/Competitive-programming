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
const int N = 1005;

int n, k, a[N], dp[N];

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i], dp[i] = 1;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j < i; ++j) {
            if(abs(a[i] - a[j]) <= k) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << *max_element(dp, dp + n + 1);

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh