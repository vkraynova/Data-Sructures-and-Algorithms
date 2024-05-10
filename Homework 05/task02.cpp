#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    int N;
    cin >> N;

    vector<int> heights;
    for (int i = 0; i < N; i++) {
        int currHeight;
        cin >> currHeight;
        heights.push_back(currHeight);
    }

    stack<int> s;
    int maxArea = 0;

    for (int i = 0; i <= N; i++) {
        while (!s.empty() && (i == N || heights[i] < heights[s.top()])) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            int area = height * width;
            maxArea = max(maxArea, area);
        }
        s.push(i);
    }

    cout << maxArea;
    return 0;
}
