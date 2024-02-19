#include <bits/stdc++.h>

using namespace std;

bool check(int x1, int y1, int x2, int y2) {
    return (x1 == x2 && y1 == y2);
}

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(check(x1 + 1, y1 + 2, x2, y2) || check(x1 + 2, y1 + 1, x2, y2) || 
       check(x1 - 1, y1 - 2, x2, y2) || check(x1 - 2, y1 - 1, x2, y2) ||
       check(x1 - 1, y1 + 2, x2, y2) || check(x1 + 2, y1 - 1, x2, y2) ||
       check(x1 + 1, y1 - 2, x2, y2) || check(x1 - 2, y1 + 1, x2, y2)) cout << "Yes"; else cout << "No";
}