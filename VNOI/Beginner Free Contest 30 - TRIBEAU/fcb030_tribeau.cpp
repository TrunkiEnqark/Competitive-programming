#include <bits/stdc++.h>

#define ll long long

using namespace std;

const string yno[] = {"No\n", "Yes\n"};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << yno[ abs(a-b) <= d && abs(a-c) <= d && abs(b-c) <= d ];
}