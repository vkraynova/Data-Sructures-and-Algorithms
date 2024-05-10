#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <queue>
using namespace std;

const size_t MAX_SIZE = 1e4 + 1;
size_t times[MAX_SIZE];

unordered_map<size_t, vector<pair<size_t, size_t>>> busMap;

void ShortestPath(size_t start, size_t* distances) {
    distances[start] = 0;
    priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, greater<pair<size_t, size_t>>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        size_t currDistance = pq.top().first;
        size_t curr = pq.top().second;
        pq.pop();

        if (currDistance > distances[curr]) {
            continue;
        }
        for (auto neighbour : busMap[curr]) {
            size_t next = neighbour.first;
            size_t weight = neighbour.second;
            size_t currentTravelTime = currDistance;
            size_t waitTime = currentTravelTime % times[curr];

            if (waitTime != 0) {
                waitTime = times[curr] - waitTime;
            }

            currentTravelTime += waitTime + weight;

            if (distances[next] > currentTravelTime) {
                distances[next] = currentTravelTime;
                pq.push({ currentTravelTime, next });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t V, E, start, end, from, to, weight;
    cin >> V >> E >> start >> end;

    size_t distances[V];
    for (size_t i = 0; i < V; ++i) {
        distances[i] = INT_MAX;
        cin >> times[i];
    }

    for (size_t i = 0; i < E; ++i) {
        cin >> from >> to >> weight;
        busMap[from].push_back({ to, weight });
    }

    ShortestPath(start, distances);

    if (distances[end] != INT_MAX) {
        cout << distances[end];
    }
    else {
        cout << -1;
    }

    return 0;
}