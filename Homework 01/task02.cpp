#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

size_t letterOccurrences[26] = { 0 };

int main() {
    size_t examCount;
    cin >> examCount;

    for (size_t examIndex = 0; examIndex < examCount; examIndex++) {
        size_t studentCount, minOccurrences;
        cin >> studentCount >> minOccurrences;
        string examRecord;
        cin >> examRecord;
       
        for (size_t recordIndex = 0; recordIndex < examRecord.length(); recordIndex++) {
            if (isupper(examRecord[recordIndex])) {
                letterOccurrences[examRecord[recordIndex] - 'A']++;
            }
        }

        for (size_t letterIndex = 0; letterIndex < 26; letterIndex++) {
            if (letterOccurrences[letterIndex] >= minOccurrences) {
                cout << char('A' + letterIndex); 
            }
        }
        cout << '\n';

       
        fill_n(letterOccurrences, 26, 0);
    }

    return 0;
}
