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
const int N = 2e5 + 5;

int n, a[N];

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int i = 1; i < n; ++i) cin >> a[i];

    sort(a + 1, a + n);

    for(int i = 1; i < n; ++i) if(a[i] - a[i - 1] > 1) {
        cout << a[i] - 1;
        return 0;
    }

    cout << n;

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh
// https://cses.fi/problemset/task/1083