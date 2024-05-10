#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> profits(n);
    for (int i = 0; i < n; i++) {
        cin >> profits[i];
    }

    vector<int> copy(n);
    for (int i = 0; i < n; i++) {
        copy[i] = profits[i];
    }

    sort(copy.begin(), copy.end());

    int indexOfMin = n;
    int indexOfMax = -1;

    for (int i = 0; i < n; i++) {
        if (profits[i] != copy[i]) {
            indexOfMin = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (profits[i] != copy[i]) {
            indexOfMax = i;
            break;
        }
    }

    if (indexOfMax == -1 && indexOfMin == n) {
        cout << 0;
    }
    else {
        cout << indexOfMax - indexOfMin + 1;
    }



    return 0;
}