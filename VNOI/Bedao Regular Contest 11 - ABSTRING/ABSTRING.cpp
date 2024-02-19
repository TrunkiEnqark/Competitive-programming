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

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> s;
    s = " " + s;

    int ans = 0;
    for(int i = 1; i <= n - 2; ++i) 
        if(s[i] == 'a') {
            int j = i;
            while(j + 2 <= n && s[j + 1] == 'b' && s[j + 2] == 'a') j += 2;
            ans = max(ans, j - i);
            if(j > i) i = j - 1;
        }

    cout << 'a';
    for(int i = 1; i <= ans / 2; ++i) cout << "ba";

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh