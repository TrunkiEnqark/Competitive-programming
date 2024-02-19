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

int n, t, ans[11];
string s;

bool ok(int k, int len) {
    for(int i = 1; i <= n - len + 1; ++i) {
        int i1 = i;
        int j1 = i1 + len - 1;
        int i2 = j1 + 1;
        int j2 = i2 + len - 1;  
        if(j2 > n) break;
        int cnt = 0;
        for(; i1 <= j1 && i2 <= j2; ++i1, ++i2) {
            cnt += (s[i1] != s[i2]);
            if(cnt > k) break;
        }
        if(cnt <= k) return true;
    }
    return false;
}

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> t >> s;
    n = s.size();
    s = "#" + s;

    for(int k = 0; k <= 10; ++k) {
        for(int i = n - 1; i >= 0; --i) {
            if(ok(k, i)) { ans[k] = i; break; }
        }
    }

    while(t--) {
        int k;
        cin >> k;

        cout << ans[k] << endl;
    }

    return 0;
}
