#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int N = 55;

int n, k, dp[N][N*N][1300];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("sumars.inp", "r", stdin);
    // freopen("sumars.out", "w", stdout);

    cin >> n >> k;

    
        
    cout << dp[n][k][0];
}