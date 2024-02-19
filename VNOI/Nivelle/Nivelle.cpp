#include <bits/stdc++.h>

using namespace std;

int n;
string s;


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> s;

    int l = -1, r = -1, ans = 26;

    vector<int> v(27, -1), f(27, -1);
    for(int i = 0; i < n; ++i) {
        int c = s[i] - 'a';
        v.erase(find(v.begin(), v.end(), f[c]));
        f[c] = i;
        v.insert(v.begin(), i);

        for(int j = 1; j <= 26; ++j) {
            if(j * (r - l + 1) < ans * (i - v[j])) {
                ans = j;
                l = v[j] + 1;
                r = i;
            }
        }
    }

    cout << l + 1 << ' ' << r + 1;

}