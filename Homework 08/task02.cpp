#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Guest {
    int begin;
    int end;
    int index;
    int indexChair;
    Guest() : begin(0), end(0), index(0) {}
    Guest(int begin, int end, int index) : begin(begin), end(end), index(index) {}
};


struct CompareEnd {
    bool operator()(const Guest& g1, const Guest& g2) {
        if (g1.end == g2.end) {
            return g1.begin > g2.begin;
        }
        return g1.end > g2.end;
    }
};

int main() {
    int n;
    cin >> n;
    vector<Guest> guests;

    for (int i = 0; i < n; i++) {
        int b, e;
        cin >> b >> e;
        guests.push_back(Guest(b, e, i));
    }

    sort(guests.begin(), guests.end(), [](const Guest& g1, const Guest& g2) {
        return g1.begin < g2.begin;
        });
    priority_queue<Guest, vector<Guest>, CompareEnd> minHeap;
    priority_queue<int, vector<int>, greater<int>> chairs;

    for (int i = 0; i < n; i++) {
        chairs.push(i);
    }

    int targetIndex = 0;
    cin >> targetIndex;
    int chairIndex = -1;

    int size = guests.size();
    for (int i = 0; i < size; i++) {

        if (guests[i].begin == guests[i].end) {
            continue;
        }

        while (!minHeap.empty() && minHeap.top().end <= guests[i].begin) {
            chairs.push(minHeap.top().indexChair);
            minHeap.pop();

        }

        if (guests[i].index == targetIndex) {
            chairIndex = chairs.top();
        }



        guests[i].indexChair = chairs.top();
        chairs.pop();
        minHeap.push(guests[i]);

    }

    cout << chairIndex << endl;

    return 0;
}
