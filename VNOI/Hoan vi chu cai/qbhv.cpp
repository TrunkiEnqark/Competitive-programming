#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define pb push_back
#define endl '\n'

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	vector<string> v; sort(all(s)); v.pb(s);
	while(next_permutation(all(s))) v.pb(s);
	cout << v.size() << endl;
	for(auto x:v) cout << x << endl;
}