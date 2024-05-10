#include <iostream>
#include <string>
using namespace std;

int countOccurence(string& word, string& symbols) {
    if (word.empty()) return 0;

    int count = 0;
    int symbolsSize = symbols.size();
    int wordSize = word.size();
    int diff = symbolsSize - wordSize;
    int i = 0;

    while (i <= diff) {
        int j;
        for (j = 0; j < wordSize; ++j) {
            if (symbols[i + j] != word[j]) {
                break;
            }
        }
        if (j == wordSize) {
            ++count;
            i += wordSize;
        }
        else {
            ++i;
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    int count = countOccurence(s1, s2);
    cout << count << '\n';

    return 0;
}

