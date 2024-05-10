#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;


int main() {
    int n, minDistance = INT_MAX;
    cin >> n;
    vector<int> grandmas;

    for (int i = 0; i < n; i++) {
        int grandma;
        cin >> grandma;
        grandmas.push_back(grandma);
    }

    unordered_map<int, int> m;

    for (int i = 0; i < n; i++) {
        if (m.find(grandmas[i]) != m.end()) {
            minDistance = min(minDistance, i - m[grandmas[i]]);
        }
        m[grandmas[i]] = i;
    }

    if (minDistance == INT_MAX) {
        cout << -1 << '\n';
    }
    else {
        cout << minDistance << '\n';
    }


    return 0;
}
