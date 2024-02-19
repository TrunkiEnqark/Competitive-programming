#include <bits/stdc++.h>

#define NAME        "matrix"

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
const int N = 1e4 + 5;

int n, m, x[N][N];

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m;

    int l = 1;
    for(int j = 2; j <= m; ++j) {
        if(!x[1][j]) {
            x[1][j] = l++;
            for(int k = j * j; k <= m; k += j) if(x[1][k] == 0) x[1][k] = x[1][j];
        }
    }

    for(int i = 2; i <= n; ++i) x[i][1] = x[1][i];

    for(int i = 2; i <= n; ++i) {
        for(int j = 2; j <= m; ++j) {
            x[i][j] = x[1][j] ^ x[i][1];
            // cout << x[i][j] << " \n"[j == m];
        }
    }

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) cout << x[i][j] + 1 << " \n"[j == m];

    int res = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            res += x[i][j] + 1;
            res %= MOD;
        }

    cout << res;

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh