#include <bits/stdc++.h>
#define fo(i,a,b) for(int i = a; i <= b; ++i)
#define fd(i,a,b) for(int i = a; i >= b; --i)
#define all(a) a.begin(), a.end()
#define pb push_back

using namespace std;

bool cmp(const string &a, const string &b) { return a + b < b + a; }

int main() {
	//freopen("test.inp", "r", stdin);
	string s;
	vector<string> v;
	while(cin >> s) v.pb(s);
	sort(all(v), cmp);
	fd(i,v.size()-1,0) cout << v[i];
	return 0;
}