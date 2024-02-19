#include <bits/stdc++.h> 

using namespace std;

const int N = 305;
const int lim = 1e7 + 7;

int n, m, w[N];
bool flag[lim];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(flag, false, sizeof flag);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> w[i];

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(w[i] <= m                && !flag[w[i]])                 ++ans, flag[w[i]] = 1; 
        for(int j = i + 1; j <= n; ++j)
            for(int k = j + 1; k <= n; ++k) {
                if(w[i] + w[k] <= m         && !flag[w[i] + w[k]])          ++ans, flag[w[i] + w[k]] = 1;
                if(w[i] + w[j] <= m         && !flag[w[i] + w[j]])          ++ans, flag[w[i] + w[j]] = 1;
                if(w[j] + w[k] <= m         && !flag[w[j] + w[k]])          ++ans, flag[w[j] + w[k]] = 1;
                if(w[i] + w[j] + w[k] <= m  && !flag[w[i] + w[j] + w[k]])   ++ans, flag[w[i] + w[j] + w[k]] = 1;
            }
    }
    cout << ans;
}