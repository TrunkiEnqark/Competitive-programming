#include <bits/stdc++.h>

using namespace std;

char solve(string a, string b) {
    if(a == b) return '=';
    if((a.back() == 'L' && b.back() != 'L') || (a.back() != 'S' && b.back() == 'S')) return '>'; 
    if((b.back() == 'L' && a.back() != 'L') || (b.back() != 'S' && a.back() == 'S')) return '<';
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < a.size() && a[i] == 'X'; ++cnt1, ++i) {}
    for(int i = 0; i < b.size() && b[i] == 'X'; ++cnt2, ++i) {}
    if(a.back() == 'S' && b.back() == 'S') {
        if(cnt1 > cnt2) return '<';
            else return '>';
    } else {
        if(cnt1 < cnt2) return '<';
            else return '>';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        // cout << a.front() << endl;
        cout << solve(a, b) << '\n';
    }
}