#include <bits/stdc++.h>

using namespace std;

int dx[] = {+1, +1, +2, +2, -1, -1, -2, -2};
int dy[] = {+2, -2, +1, -1, -2, +2, -1, +1};

bool check(int i, int j, int m, int n) {
    for(int k = 0; k < 8; ++k) {
        int u = i + dx[k];
        int v = j + dy[k];
        if(u > 0 && u <= m && v > 0 && v <= n) return true;
    }
    return false;
}

void pr() {
    int m, n;
    cin >> m >> n;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j) {
            if(!check(i, j, m, n)) {
                cout << i << ' ' << j << endl;
                return;
            }
        }
    cout << m << ' ' << n << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;

    while(t--) {
        pr();
    }
}