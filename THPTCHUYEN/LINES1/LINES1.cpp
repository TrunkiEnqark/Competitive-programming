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

const int N = 1e5 + 5;

int n;
multiset<int> s;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    
    while(n--) {
        int d;
        cin >> d;
        s.insert(d);
        multiset<int>::iterator it = s.lower_bound(d);
        ++it;
        if(it != s.end()) s.erase(it);
    }
    cout << s.size();

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9843