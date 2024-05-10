#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(vector<int>& arr, int l, int r, int x) {
    while (r >= l) {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, D;
    cin >> N >> D;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int count = 0;
    for (int i = 0; i < N; i++) {
        int target = arr[i] + D;
        int result = binarySearch(arr, i + 1, N - 1, target);

        if (result != -1)
            count++;
    }

    cout << count;
    return 0;
}