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
const int N = 1e5 + 500;

bool maximize(int &a, int b) {
    return (a < b ? a = b, 1 : 0);
}

bool minimize(int &a, int b) {
    return (a > b ? a = b, 1 : 0);
}

int n, a[N][3], dp[N][3];

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i][0] >> a[i][1] >> a[i][2];  

    for(int i = 0; i < n; ++i) {
        dp[i + 1][0] = max(dp[i][1], dp[i][2]) + a[i + 1][0];
        dp[i + 1][1] = max(dp[i][0], dp[i][2]) + a[i + 1][1];
        dp[i + 1][2] = max(dp[i][0], dp[i][1]) + a[i + 1][2];
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]});

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh