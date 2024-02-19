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

int n;
double dp[N];

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;

    dp[0] = 1;
    for(int i = 1; i <= n; ++i) {
        double a;
        cin >> a;
        for(int j = i; j >= 1; --j) 
            dp[j] = dp[j - 1] * a + dp[j] * (1 - a);
    }

    cout << fixed << setprecision(10) << dp[n/2 + 1];

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh