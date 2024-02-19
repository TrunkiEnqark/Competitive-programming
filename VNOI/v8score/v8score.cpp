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

int s, k, n, a[22][22], dp[22][22];
ii trace[22][22];

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> s >> k >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= k; ++j) cin >> a[i][j];
    
    for(int j = 1; j <= k; ++j) {
        for(int i = 1; i <= n; ++i) {
            for(int l = 1; l <= n; ++l) 
                if(l != i) {
                    if(a[i][j] >= a[l][j - 1] && dp[i][j] < dp[l][j - 1] + a[i][j]) {
                        dp[i][j] = dp[l][j - 1] + a[i][j];
                        trace[i][j] = {l, j - 1};
                    }
                }
        }
    }

    
    for(int i = 1; i <= n; ++i) {
        if(dp[i][k] == s) {
            cout << "YES\n";
            vector<ii> ans;
            ans.pb({i, k});
            int x = i, y = k;
            while(x != 0 && y != 0) {
                ans.pb(trace[x][y]);
                // cout << trace[x][y].first << ' ' << trace[x][y].second << endl;
                x = trace[x][y].first;
                y = trace[x][y].second;
            }

            reverse(all(ans));
            for(auto it : ans) cout << a[it.first][it.second] << ' ';

            return 0;
        }
    }

    cout << "NO";

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh