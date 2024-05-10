#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

size_t findMaxCommonSequence(const string& s1, const string& s2) {

    size_t maxSequence = 0;

    for (size_t i = 0; i < s1.size(); i++) {
        size_t currSequence = 0;
        size_t firstIndex = i;
        size_t j = 0;

        while (j < s2.size() && firstIndex < s1.size()) {

            if (s1[firstIndex] != s2[j]) {
                currSequence = 0;
            }
            else {
                currSequence++;
                maxSequence = max(maxSequence, currSequence);
            }
            j++;
            firstIndex++;
        }
    }
    return maxSequence;
}

int main() {

    string s1, s2;
    cin >> s1 >> s2;
    size_t maxSeq = findMaxCommonSequence(s1, s2);
    cout << maxSeq;
    return 0;
}