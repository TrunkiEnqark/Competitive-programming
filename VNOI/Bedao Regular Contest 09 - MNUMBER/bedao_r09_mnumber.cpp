#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int c;
    cin >> c;
    if(c == 1) { cout << "NO"; return 0; }
    for(int u = 1; u * u <= c; ++u) {
        if(c%u == 0 && c/u >= u && (c/u - u) % 2 == 0 && (u + c/u) % 2 == 0) {
            cout << "YES\n";
            cout << (c/u + u)/2 << ' ' << (c/u - u)/2;
            return 0;
        }
    }
    cout << "NO";
}