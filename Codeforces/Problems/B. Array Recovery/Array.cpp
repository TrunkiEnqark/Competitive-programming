#include <bits/stdc++.h>

using namespace std;

void pr() {
    int n;
    cin >> n;
    int d[n + 1], a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> d[i];
    }

    for(int i = 1; i <= n; ++i) {
        if(i == 1) a[i] = d[i];
            else {
                a[i] = d[i] + a[i - 1];
                int tmp = a[i - 1] - d[i];
                if(tmp >= 0  && a[i] != tmp) {
                    cout << -1 << endl;
                    return;
                }
            } 
    }

    for(int i = 1; i <= n; ++i) cout << a[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("array.inp", "r", stdin);
    // freopen("array.out", "w", stdout);

    int t;
    cin >> t;
    // cout << endl;
    while(t--) pr();
}