#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int m, n, a[N], x[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> m >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    for(int i = 1; i <= m; ++i) x[i] = 1;
    int l = 1, r = m, k = 1;
    while(l <= r) {
        
        ++l, --r;
    }
}