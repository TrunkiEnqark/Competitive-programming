#include <bits/stdc++.h>

#define NAME ""

#define fo(i, a, b) for(int i = a; i <= b; ++i)
#define all(a)		a.begin(), a.end()

#define pb 			push_back
#define endl		'\n'
#define ll 			long long
#define ii 			pair<int, int>
#define fi 			first
#define se 			second

using namespace std;

ll gcd(ll a, ll b) {
	if(a == 0) return b;
	return gcd(b%a, a);
}

struct data {
	string name;
	int toan, tin;

	data() {}
	data(string na, int to, int ti) {
		name = na;
		toan = to;
		tin = ti;
	}
};

bool cmp(const data &a, const data &o) {
		if(a.name < o.name) return true;
			else if(a.name == o.name) {
				if(a.toan + a.tin < o.toan + o.tin) return true;
					else if(a.toan + a.tin == o.toan + o.tin) {
						return a.toan < o.toan;
					}
			} 
		return false;
	}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen(NAME".inp", "r", stdin);
	// freopen(NAME".out", "w", stdout);

	int n;
	cin >> n;
	vector<data> a(n);
	for(data &i : a) cin >> i.name >> i.toan >> i.tin;
	
	sort(all(a), cmp);
	
	for(data i : a) 
		cout << i.name << ' ' << i.toan << ' ' << i.tin << '\n';

	return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9864