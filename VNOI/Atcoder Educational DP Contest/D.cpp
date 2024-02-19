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
const int N = 105;
const int W = 1e5 + 5;

int n, w, p[N], v[N];
ll dp[N][W];

bool maximize(ll &a, ll b) {
    return (a < b ? a = b, 1 : 0);
}

bool minimize(int &a, int b) {
    return (a > b ? a = b, 1 : 0);
}


ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> w;
    for(int i = 1; i <= n; ++i) cin >> p[i] >> v[i];

    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= w; ++j) dp[i][j] = dp[i - 1][j];

        for(int j = 0; j <= w; ++j) {
            if(j - p[i] >= 0) {
                maximize(dp[i][j], (ll) dp[i - 1][j - p[i]] + v[i]);
                // if(i == 3) cout << dp[i - 1][j - p[i]] << endl;
            }
            // if(j + p[i + 1] <= w) maximize(dp[i + 1][j + p[i + 1]], dp[i][j] + v[i + 1]);
        }
    }

    // for(int i = 1; i <= n; ++i)
    //     for(int j = 0; j <= w; ++j) cout << dp[i][j] << " \n"[j == w];

    ll res = 0;
    for(int i = 0; i <= w; ++i) res = max(res, dp[n][i]); 
    cout << res;

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh