#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

const size_t INF = INT_MAX;

unordered_map<size_t, vector<pair<size_t, size_t>>> g;
size_t n, m, startIndex, endIndex;

void dijkstra(size_t start, size_t end) {
    vector<size_t> distance(n + 1, INF);
    vector<bool> visited(n + 1, false);

    priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, greater<pair<size_t, size_t>>> pq;

    distance[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        size_t u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (const auto& neighbor : g[u]) {
            size_t v = neighbor.first;
            size_t weight = neighbor.second;

            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({ distance[v], v });
            }
        }
    }

    cout << distance[end] << endl;
}

int main() {
    cin >> n >> m;

    for (size_t i = 0; i < m; i++) {
        size_t from, to, weight;
        cin >> from >> to >> weight;
        g[from].push_back({ to, weight });
        g[to].push_back({ from, weight });
    }

    cin >> startIndex >> endIndex;

    dijkstra(startIndex, endIndex);

    return 0;
}