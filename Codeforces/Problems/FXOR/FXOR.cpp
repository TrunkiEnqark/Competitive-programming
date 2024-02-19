#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int trie[N * 32][2], n, cnt = 2;

void insert(int msk) {
    int u = 1;
    for(int i = 31; i >= 0; --i) {
        int j = (msk >> i) & 1;
        if(trie[u][j] == -1) trie[u][j] = cnt++;
        u = trie[u][j];
    }
}

int find(int msk) {
    int u = 1, res = 0;
    for(int i = 31; i >= 0; --i) {
        int j = (msk >> i) & 1;
        if(trie[u][!j] != -1) {
            u = trie[u][!j];
            res = (res << 1) + !j;
        } else {
            u = trie[u][j];
            res = (res << 1) + j;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for(int i = 1; i < N * 32; ++i) trie[i][0] = trie[i][1] = -1;
    cin >> n;
    for(int a, i = 0; i < n; ++i) {
        cin >> a;
        insert(a);
    }

    int q;
    cin >> q;
    while(q--) {
        int x;
        cin >> x;
        cout << find(x) << ' ';
    }

    return 0;
}