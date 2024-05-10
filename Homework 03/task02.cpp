#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    sort(points.begin(), points.end());

    for (int i = 0; i < q; i++) {
        int min, max;
        cin >> min >> max;

        auto lower = lower_bound(points.begin(), points.end(), min);
        auto upper = upper_bound(points.begin(), points.end(), max);

        if (min > max) {
            cout << 0 << '\n';
        }
        else {
            cout << upper - lower << '\n';
        }


    }


    return 0;
}
