#include <bits/stdc++.h>

#define NAME        ""

#define ll          long long
#define ii          pair<int, int>
#define ld          long double
#define fi          first
#define se          second
#define endl        '\n'
#define pb          push_back

#define OK          cout << "ok\n";
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

using namespace std;

const int MOD = 1e9 + 7;
const int base = 29;
const int N = 105;
const int maxMSK = 1 << 19;

// int prime[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int d[] = {0, 0, 1, 2, 0, 3, 0, 4, 0, 0, 0, 5, 0, 6, 0, 0, 0, 7, 0, 8, 0, 0, 0, 9, 0, 0, 0, 0, 0, 10, 0, 11, 0, 0, 0, 0, 0, 12, 0, 0, 0, 13, 0, 14, 0, 0, 0, 15, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 17, 0, 18, 0, 0, 0, 0, 0, 19, 0, 0, 0, 0, 0};

int n, a[N], dp[N][maxMSK];

bool isPrime(int n) {
    for(int i = 2; i*i <= n; ++i) if(n%i == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i] == 1) {
            ++cnt;
            // continue;
        }
        int msk = 0;
        map<int, int> m;
        int tmp = a[i];
        for(int j = 2; j <= tmp; ++j) {
            if(tmp % j == 0) {
                ++m[j];
                tmp /= j;
            }
        }
        for(auto it : m) {
            msk |= (1 << (d[it.first] - 1));
        }
        // if(msk == 0) continue;
        for(int preMsk = 0; preMsk < (1 << 19); ++preMsk) {
            dp[i][preMsk] = max(dp[i][preMsk], dp[i - 1][preMsk]);
            if(!(preMsk & msk) && msk != 0) {
                int MSK = preMsk | msk;
                // cout << MSK << endl;
                if(MSK >= 0 && MSK < maxMSK && msk < maxMSK) dp[i][MSK] = max(dp[i][MSK], dp[i - 1][preMsk] + 1);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        int now = 0;
        for(int msk = 0; msk < (1 << 19); ++msk) ans = max(ans, dp[i][msk]);
        // cout << now << endl;
    }
    cout << ans + cnt;

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh