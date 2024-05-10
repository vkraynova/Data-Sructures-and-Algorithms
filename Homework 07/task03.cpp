#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t q, minXOR = INT_MAX;
    cin >> q;
    set<size_t> s;
    set<size_t>::iterator it;

    s.insert(0);

    for (size_t i = 0; i < q; i++) {
        size_t curr;
        cin >> curr;
        s.insert(curr);
        it = s.find(curr);

        if (it != s.begin()) {
            size_t xorWithPrev = *prev(it) ^ curr;
            minXOR = min(xorWithPrev, minXOR);
        }

        if (next(it) != s.end()) {
            size_t xorWithNext = *next(it) ^ curr;
            minXOR = min(xorWithNext, minXOR);
        }

        cout << minXOR << '\n';
    }

    return 0;
}