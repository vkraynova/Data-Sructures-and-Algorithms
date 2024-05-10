#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;


int main() {

    int N;
    cin >> N;

    vector<int> fighters;

    for (int i = 0; i < N; i++) {

        int power;
        cin >> power;
        fighters.push_back(power);
    }

    deque<int> positives;


    for (int i = 0; i < N; i++) {

        int curr;
        curr = fighters[i];

        if (curr > 0) {
            positives.push_front(curr);
            continue;
        }

        while (true) {

            if (positives.empty()) {
                cout << curr << ' ';
                break;
            }

            int front = positives.front();

            if (-curr > front) {
                positives.pop_front();
                continue;

            }
            else if (-curr == front) {
                positives.pop_front();
                break;

            }
            else {
                break;
            }
        }

    }

    while (!positives.empty()) {

        cout << positives.back() << ' ';
        positives.pop_back();
    }

    return 0;
}