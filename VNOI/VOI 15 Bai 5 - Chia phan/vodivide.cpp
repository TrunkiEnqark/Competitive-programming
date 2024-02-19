#include <bits/stdc++.h>

#define ll 			long long
#define ii 			pair<int, int>
#define ib 			pair<int, bool>
#define pll 		pair<ll, ll>
#define iii 		pair<int, ii>
#define iiii 		pair<ii, ii>
#define pb 			push_back
#define mp 			make_pair
#define fi 			first
#define se 			second
#define fo(i,a,b)	for(int i = a; i <= b; ++i)
#define fod(i,a,b)  for(int i = a; i >= b; --i)
#define rep(i,a)	for(int i = 0; i < a; ++i)
#define all(a)		a.begin(), a.end()
#define maxx(a,b,c) max(a, max(b, c))
#define minn(a,b,c) min(a, min(b, c)) 

using namespace std;

const int INF = (int)1e9;
const int base = 31;
const ll MOD = 1000000003;
const int N = 5005;

struct pack {
	int a, b, index;
};

bool cmp(const pack &a, const pack &b) { return a.a < b.a; };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	vector<pack> v(n);

	for(int i = 0; i < n; ++i) v[i].index = i+1;
	for(int i = 0; i < n; ++i) cin >> v[i].a;
	for(int i = 0; i < n; ++i) cin >> v[i].b;
	sort(all(v), cmp);

	ll res = 0;
	priority_queue<ii> qu;
	vector<bool> take(n, false);
	for(int i = 0; i < n; ++i) {
		qu.push(mp(v[i].b, i));
		if(i%2 == 0) {
			ii t = qu.top(); qu.pop();
			res += (ll) t.fi;	
			take[t.se] = true;
		}
	}

	cout << res << '\n';
	vector<int> st;
	for(int i = 0; i < n; ++i) 
		if(take[i]) st.pb(v[i].index); 
			else { 
				cout << v[i].index << ' ' << st.back() << '\n';
				st.pop_back();
			}
	return 0;
}