#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Boy {
    double di;
    double ti;
    int index;

    double efficiency() const {
        return di * di / ti;
    }
};

bool compareEfficiency(const Boy& a, const Boy& b) {
    if (a.efficiency() != b.efficiency())
        return a.efficiency() > b.efficiency();

    return a.di > b.di;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Boy> boys(n);

    for (int i = 0; i < n; i++) {
        cin >> boys[i].di >> boys[i].ti;
        boys[i].index = i + 1;
    }

    stable_sort(boys.begin(), boys.end(), compareEfficiency);

    for (int i = 0; i < n; i++) {
        cout << boys[i].index << " ";
    }
    return 0;
}