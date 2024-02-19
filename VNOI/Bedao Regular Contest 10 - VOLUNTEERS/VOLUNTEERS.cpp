#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, m, b[N];
multiset<int> a;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    // b.resize(m);
    for(int d, i = 0; i < n; ++i) { cin >> d; a.insert(d); } 
    // for(auto &it : b) cin >> it;
    for(int i = 0; i < m; ++i) cin >> b[i];

    // sort(a.begin(), a.end());

    for(int i = 0; i < m; ++i) {
        auto it = a.upper_bound(b[i]);
        if(it == a.begin()) continue;
        --it;
        a.erase(it);
    }

    if(!a.empty()) cout << *a.rbegin(); else cout << -1;
}