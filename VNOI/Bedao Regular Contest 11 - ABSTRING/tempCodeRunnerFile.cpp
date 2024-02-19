#include <bits/stdc++.h>

#define NAME        ""

#define ILTQ				 	int main()
#define ll          			long long
#define ii         		  		pair<int, int>
#define ld          			long double
#define fi          			first
#define se          			second
#define endl        			'\n'
#define pb          			push_back

#define OK          			cout << "ok\n";
#define all(a)      			a.begin(), a.end()
#define rall(a)     			a.rbegin(), a.rend()

using namespace std;

const int MOD = 1e9 + 7;
const int base = 29;
const int N = 1e6 + 6;

int n;
string s;

bool check(int l, int r) {
    return (s[l] == 'a' && s[l + 1] == 'b' && s[r] == 'a');
}

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> s;
    s = " " + s;

    string ans;
    int x = 1, y = 1;
    for(int i = 1; i <= n; ++i) {
        int u = 0;
        string cur = s.substr(i, 2);
        for(int j = i + 2; j <= n; ++j) {
            // int l = r - 2;
            cur += s[j];
            if(check(j - 2, j)) {
                ++u;
            }
            int v = j - i + 1;
            if((double) u / v < (double) x / y) {
                if(x == 1 && y == 1) ans = cur;
                    else ans = min(ans, cur);
                cout << cur << endl;
                x = u;
                y = v;
            }
        }
    }

    cout << ans;

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh