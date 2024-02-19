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

const int N = 1e7;

int n;
bitset<N> isPrime;
// vector<int> cnt;
vector<int> prime;
vector<ll> dp(N);

void init() {
    isPrime[2] = true;
    prime.assign(1, 2);

    for(int i = 3; i <= N; i += 2) isPrime.set(i);
    for(int i = 3; i <= N; i += 2) if(isPrime[i]) {
        prime.pb(i);
        if((ll) i * i > N) continue;
        for(int j = i * i; j <= N; j += 2*i) isPrime.reset(j);
    }

    n = prime.size();
    for(int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + prime[i - 1]; 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    init();
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        int r1 = lower_bound(all(prime), a) - prime.begin();
        int r2 = upper_bound(all(prime), b) - prime.begin();
        // cout << r1 << ' ' << r2 << endl;
        cout << fixed << setprecision(2) << (double) (dp[r2] - dp[r1]) / (r2 - r1) << endl;
    }

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/8255