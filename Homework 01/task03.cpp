#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> hungerEndurance(N);

    for (int i = 0; i < N; i++) {
        cin >> hungerEndurance[i];
    }

    sort(hungerEndurance.begin(), hungerEndurance.end());

    int minDifference = INT_MAX;

    for (int i = 0; i + K - 1 < N; i++) {
        int minHunger = hungerEndurance[i];
        int maxHunger = hungerEndurance[i + K - 1];
        minDifference = min(minDifference, maxHunger - minHunger);
    }

    cout << minDifference;

    return 0;
}