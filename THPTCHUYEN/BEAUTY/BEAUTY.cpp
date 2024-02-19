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

int ans[N];

int calc(int s) {
    int res = 0;
    for(; s > 0; s /= 10) res += (s%10)*(s%10);
    return res;
}

bool isPrime(int a) {
    if(a == 2) return true;
    if(a%2 == 0 || a < 2) return false;
    for(int i = 3; i*i <= a; i += 2) if(a%i == 0) return false;
    return true;
}

void init() {
    int s = 1, i = 1;
    while(i <= 1e5) {
        if(isPrime(calc(s))) ans[i++] = s;
        ++s;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    init();
    int n;
    cin >> n;
    cout << ans[n];

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9854