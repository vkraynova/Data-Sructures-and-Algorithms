#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

double getDistance(int x1, int y1, int x2, int y2) {

    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

struct Position {

    int x, y;
    double distance;

    Position(int x, int y, double distance) : x(x), y(y), distance(distance) {}

    struct CompareDistance {
        bool operator()(const Position& p1, const Position& p2) const {
            if (p1.distance == p2.distance) {
                if (p1.x == p2.x) {
                    return p1.y < p2.y;
                }
                return p1.x < p2.x;
            }
            return p1.distance < p2.distance;
        }
    };
};



int main() {

    int currX, currY;
    size_t landmarks, closestLandmarks;
    cin >> currX >> currY >> landmarks >> closestLandmarks;

    priority_queue<Position, vector<Position>, Position::CompareDistance> maxHeap;

    for (size_t i = 0; i < landmarks; i++) {
        int X, Y;
        cin >> X >> Y;

        double distance = getDistance(currX, currY, X, Y);
        maxHeap.push(Position(X, Y, distance));

        if (maxHeap.size() > closestLandmarks) {
            maxHeap.pop();
        }
    }

    stack<Position> s;
    while (!maxHeap.empty()) {
        s.push(maxHeap.top());
        maxHeap.pop();
    }

    while (!s.empty()) {
        Position landmark = s.top();
        s.pop();
        cout << landmark.x << " " << landmark.y << "\n";
    }

    return 0;
}