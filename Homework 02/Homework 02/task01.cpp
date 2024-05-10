#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


size_t getIndex(char symbol) {
    if (symbol >= '0' && symbol <= '9')
        return symbol - '0';

    if (symbol >= 'a' && symbol <= 'z')
        return 10 + symbol - 'a';

    return 36 + symbol - 'A';
}

char getChar(size_t index) {
    if (index >= 0 && index < 10)
        return '0' + index;

    if (index >= 10 && index < 36)
        return 'a' + index - 10;

    return 'A' + index - 36;
}

int main() {

    size_t counts[62]{ 0 };

    size_t playersAmount;
    cin >> playersAmount;

    string input;
    cin >> input;

    for (int i = 0; i < playersAmount; i++) {
        counts[getIndex(input[i])]++;
    }

    for (int i = 0; i < 62; i++) {
        cout << string(counts[i], getChar(i));
    }
}