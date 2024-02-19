#include <bits/stdc++.h>

using namespace std;

const string yno[2] = {"NO\n", "YES\n"};

int n, m, q;
vector<string> s;

bool check(string x) {
	//trái sang phải & phải sang trái
	for(int i = 0; i < n; ++i) {
		for(int l = 0; l < m; ++l) {
			string tmp;
			for(int r = l; r < m; ++r) {
				tmp += s[i][r];
				if(tmp == x) return true;
				string tmp2 = tmp;
				reverse(tmp2.begin(), tmp2.end());
				if(tmp2 == x) return true;
			}
		}
	}

	//trên xuống dưới & dưới lên trên
	for(int j = 0; j < m; ++j) {
		string tmp;
		for(int l = 0; l < n; ++l)
			for(int r = l; r < n; ++r) {
				tmp += s[j][r];
				if(tmp == x) return true;
				string tmp2 = tmp;
				reverse(tmp2.begin(), tmp2.end());
				if(tmp2 == x) return true;
			}
	}

	//dưới trái lên trên phải & ngược lại
	for(int i = n-1; i >= 0; --i)
		if(i > m) break; else {
			string tmp;
			for(int k = i; k >= 0; --k) {
				tmp += s[k][k];
				if(tmp == x) return true;
				string tmp2 = tmp;
				reverse(tmp2.begin(), tmp2.end());
				if(tmp2 == x) return true;
			}
		}

	//trên trái xuống dưới phải & ngược lại
	for(int i = 0; i < n; ++i)
		if(i > m) break; else {
			string tmp;
			for(int k = i; k < n; ++k) {
				tmp += s[k][k];
				if(tmp == x) return true;
				string tmp2 = tmp;
				reverse(tmp2.begin(), tmp2.end());
				if(tmp2 == x) return true;
			}
		}

	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> q;
	s.resize(n);
	for(int i = 0; i < n; ++i) cin >> s[i];
	while(q--) {
		string x; cin >> x;
		cout << yno[check(x)];
	}
}