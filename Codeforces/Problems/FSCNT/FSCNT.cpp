#include <bits/stdc++.h>

using namespace std;

const int L = 1e7 + 5;
const int MOD = 1e9 + 7;

int k[L + 1], cnt[L + 1];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // sieve();
    int n;
    cin >> n;
    // for(int i = 1; i <= n; ++i) ++f[k[i]];

    for(int i = 1; i <= n; ++i) k[i] = 1;

    for(int i = 1; i*i <= n; ++i) 
        for(int j = i*i; j <= n; j += i*i) k[j] = j / (i * i);

    for(int i = 1; i <= n; ++i) ++cnt[k[i]];

    long long ans = 1;
    for(int i = 1; i <= n; ++i) {
        ans = (1ll * ans * (cnt[i] + 1)) % MOD;
    }
    cout << ans;
}