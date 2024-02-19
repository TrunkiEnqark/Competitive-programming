#include <bits/stdc++.h>
using namespace std;
const int cs = 1e6 + 7;
const long long mod = 1e9 + 7;
const int INF = mod;
const int maxN = 1e3 + 7;
 
#define input cin
#define output cout
#define ll long long 
#define pii pair<int,int>
#define endl '\n'

int t;
int dx[] = {-2,-2,-1,-1,1,1,2,2};
int dy[] = {-1,1,-2,2,-2,2,-1,1};

int main() {
    ios_base::sync_with_stdio(false);
    input.tie(NULL);
    output.tie(NULL);
    freopen("array.inp", "r", stdin);
    freopen("array.ans", "w", stdout);
    input >> t;
    while (t--) {
        int n;
        input >> n;
        int a[n + 1] = {};
        ll dp[n + 1] = {};
        for (int i = 1;i<=n;i++) {
            input >> a[i];
        }
        dp[1] = a[1];
        bool ok = true;
        for (int i = 2;i<=n;i++) {
            ll cong = dp[i - 1] + a[i];
            ll tru = dp[i - 1] - a[i];
            if (cong >= 0 && tru >= 0) {
                if (cong != tru) {
                    output << - 1 << endl;
                    ok = false;
                    break;
                } else {
                    dp[i] = dp[i - 1] + a[i];
                }
            } else {
                dp[i] = max(cong,tru);
             }
        }
        if (ok) {
            for (int i = 1;i<=n;i++) {
                output << dp[i] << ' ';
            }
            output << endl;
        }
    }
    return 0;  
}