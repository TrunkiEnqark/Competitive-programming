#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	string sb, se; cin >> sb >> se;
	int ans = sb.size() + se.size(), res = ans;
	string tmp;
	for(int i = 0; i < (int) se.size(); ++i) {
		tmp += se[i];
		if(sb.size() < i+1) break;
		string t1 = se.substr(0, i+1), t2 = sb.substr(sb.size() - (i+1), i+1);
		if(t1 == t2) res = min(res, ans - (i+1));
	}
	cout << res;
}