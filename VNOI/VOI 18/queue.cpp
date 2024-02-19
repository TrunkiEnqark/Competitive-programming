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
const int N = 50005;

int n, m, x[N], y[N];
vector<int> v[N];

bool ok(int len) {
    for(int i = 1; i <= n; ++i) v[i].clear();
    for(int i = 1; i <= len; ++i) v[x[i]].push_back(y[i]);

    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 1; i <= n; ++i) {
        for(auto it : v[i]) pq.push(it);
        if(pq.empty()) continue;
        if(pq.top() < i) return false;
        pq.pop();
    }
    return pq.empty();
}

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= m; ++i) cin >> x[i] >> y[i];

        int l = 1, r = min(n, m);
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(ok(mid)) {
                l = mid + 1;
            } else r = mid - 1;
        }

        cout << l - 1 << endl;
    }

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh