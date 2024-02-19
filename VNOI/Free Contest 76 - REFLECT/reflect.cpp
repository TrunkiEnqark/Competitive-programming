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

struct point {
    double x, y;
} g, i, gg;

ll n, a, b, c;

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    double u = 0, v = 0;
    for(int i = 0; i < n; ++i) {
        int p, q;
        cin >> p >> q;
        u += p;
        v += q;
    }
    g = {u/n, v/n};
    cin >> a >> b >> c;
    // ax + by + c = 0
    double d = b*g.x - a*g.y;
    i.x = (b*d - a*c) / (a*a + b*b);
    i.y = (-c - a*i.x) / b;
    cout << fixed << setprecision(4) << g.x << ' ' << g.y << endl << i.x*2 - g.x << ' ' << i.y*2 - g.y;

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh