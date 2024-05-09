#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int symbolOccurrences(string& word, int charsCount, char symbol) {
    int wordLength = word.length();
    int remainderLength = charsCount % wordLength;
    int occurencesInWord = 0;

    for (int i = 0; i < wordLength; i++) {
        if (word[i] == symbol) {
            occurencesInWord++;
        }
    }

    int occurencesCount = occurencesInWord * (charsCount / wordLength);

    for (int i = 0; i < remainderLength; i++) {
        if (word[i] == symbol) {
            occurencesCount++;
        }
    }

    return occurencesCount;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word;
    cin >> word;

    int charsCount;
    cin >> charsCount;

    char symbol;
    cin >> symbol;

    cout << symbolOccurrences(word, charsCount, symbol);

    return 0;
}