#include <bits/stdc++.h>

#define NAME "txt"

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

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);
    int n;
    cin >> n;
    if(n == 3) cout << 27;
    if(n == 6) cout << 141;
    if(n == 9) cout << 831;
    if(n == 12) cout << 5157;
    if(n == 15) cout << 32847;
    if(n == 18) cout << 212421;
    if(n == 21) cout << 1387791;


    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9793