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
const int N = 3005;

int dp[N][N];
string s, t;

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = "#" + s;
    t = "#" + t;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(s[i] == t[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }

    int i = n, j = m;
    string res;
    while(i > 0 && j > 0) {
        if(s[i] == t[j]) res = s[i] + res, i--, j--;
            else if(dp[i - 1][j] > dp[i][j - 1]) i--; 
                else j--;
    }

    // reverse(all(res));
    cout << res;

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh