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

const ll MOD = 1e9 + 7;
const int base = 29;
const int N = 1005;

int n, m;
ll dp[N][N];
char c[N][N];

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) cin >> c[i][j];

    dp[1][1] = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            if(c[i][j] == '.' && (i > 1 || j > 1)) dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }

    cout << dp[n][m];

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh