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
const int N = 3e5 + 5;

int n;
string s;

bool check(int i, int j) {
    for(int k = i; k < j; ++k) 
        if(s[k] != s[k + 1]) return true;
    return false;
}

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> s;
    s = "#" + s + "#";

    ll res = 0, len = 1;
    for(int i = 1; i <= n + 1; ++i) {
        if(s[i] == s[i - 1]) len++;
            else {
                res += len * (len - 1) / 2;
                len = 1;
            }
    }

    cout << res;

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh