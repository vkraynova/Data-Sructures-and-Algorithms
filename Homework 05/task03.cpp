#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;

    vector<int> hunger;
    stack<pair<int, int>> final;

    for (int i = 0; i < N; i++) {
        int currHunger;
        cin >> currHunger;
        hunger.push_back(currHunger);
    }

    int daysToFinal = 0;

    for (int i = 0; i < N; i++) {
        int currDaysToFinal = 0;
        while (!final.empty() && final.top().first >= hunger[i]) {
            currDaysToFinal = max(currDaysToFinal, final.top().second);
            final.pop();
        }

        if (!final.empty()) {
            final.top().second = max(currDaysToFinal, final.top().second) + 1;
            daysToFinal = max(daysToFinal, final.top().second);
        }

        final.push({ hunger[i],0 });
    }

    cout << daysToFinal;

    return 0;
}