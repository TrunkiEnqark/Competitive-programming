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

const int MOD = 123456789;
const int base = 29;

void process() {
    string s;
    cin >> s;
    int n = s.size();
    if(!isdigit(s.back())) n--;
    s = "#" + s + "+";
    ll sign = 1, num = 1, ans = 0, last = 0;
    for(int i = 1; i <= n + 1; ++i) {
        // cout << ans << ' ';
        if(isdigit(s[i])) {
            last = s[i] - '0';
        } else {
            if(s[i] == '+' || s[i] == '-') {
                int x = sign * last;
                ans += num * x;
                num = 1;
                ans %= MOD;
                if(s[i] == '+') sign = 1; else sign = -1;
            } else {
                int x = sign * last;
                num *= x;
                num %= MOD;
                sign = 1;
            }
        }
    }
    // cout << endl;
    cout << ans % MOD << endl;
}

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int t;
    cin >> t;
    while(t--) {
        // solve();
        process();
    }

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh