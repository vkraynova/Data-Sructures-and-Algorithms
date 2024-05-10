#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    int N, M;
    cin >> N >> M;

    vector<int> subSequence;
    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;
        subSequence.push_back(num);
    }

    set<int> remaining;
    for (int i = 1; i <= N; ++i) {
        if (find(subSequence.begin(), subSequence.end(), i) == subSequence.end()) {
            remaining.insert(i);
        }
    }
    vector<int> result;
    set<int> ::iterator itr;
    itr = remaining.begin();
    int i = 0;

    while (itr != remaining.end() && i < M) {
        if (*itr < subSequence[i]) {
            result.push_back(*itr);
            itr++;

        }
        else {
            result.push_back(subSequence[i]);
            i++;
        }
    }

    while (itr != remaining.end()) {
        result.push_back(*itr);
        itr++;;
    }
    while (i < M) {
        result.push_back(subSequence[i]);
        i++;
    }

    for (auto j : result) {
        cout << j << " ";
    }




    return 0;
}
