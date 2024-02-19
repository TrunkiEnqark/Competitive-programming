#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int x[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    int k = n - 1;
    x[1] = 1;
    for(int j = 2, i = k, p = 1; i > 0; ++j, --i, p *= -1) {
        x[j] = x[j - 1] + p*i;
    }

    for(int i = 1; i <= n; ++i) cout << x[i] << ' ';
}