#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int countOddSubarrays(vector<int>& nums, int median) {

    int size = nums.size();
    int medianIndex = find(nums.begin(), nums.end(), median) - nums.begin();
    int result = 0;

    unordered_map<int, int> mp;

    if (medianIndex == size) {
        return 0;
    }

    for (int i = medianIndex, balance = 0; i >= 0; i--) {
        if (nums[i] < median)
            balance--;

        else if (nums[i] > median)
            balance++;

        mp[balance]++;
    }

    for (int i = medianIndex, balance = 0; i < size; i++) {
        if (nums[i] < median)
            balance--;

        else if (nums[i] > median)
            balance++;

        result += mp[-balance];
    }

    return result;
}

int main() {

    int N;
    int B;
    cin >> N >> B;

    vector<int> nums;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        nums.push_back(num);
    }

    int result = countOddSubarrays(nums, B);
    cout << result;

    return 0;
}
