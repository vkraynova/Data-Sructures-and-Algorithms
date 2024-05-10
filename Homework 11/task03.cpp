#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <climits>

using namespace std;

struct Tunnel {
    int endVertex;
    int distance;
    int weightLimit;
};

vector<deque<Tunnel>> tunnels;

long long maxTravelDistance;
int destVertex, minWeight = -1;

bool pathExistsWithGivenWeight(int weightLimit) {
    const int numVertices = tunnels.size();
    vector<long long int> distances(numVertices, INT_MAX);
    vector<bool> visited(numVertices, false);
    distances[0] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({ 0, 0 });

    long long newDistance;
    int currentVertex;

    while (!pq.empty()) {
        currentVertex = pq.top().second;
        pq.pop();

        visited[currentVertex] = true;

        if (currentVertex == destVertex) {
            break;
        }

        for (auto tunnel : tunnels[currentVertex]) {
            if (tunnel.weightLimit > weightLimit || visited[tunnel.endVertex]) {
                continue;
            }
            auto& neighborDistance = distances[tunnel.endVertex];
            newDistance = (long long)distances[currentVertex] + tunnel.distance;

            if (newDistance < neighborDistance) {
                pq.push({ newDistance, tunnel.endVertex });
                neighborDistance = newDistance;
            }
        }

        while (!pq.empty() && visited[pq.top().second]) {
            pq.pop();
        }
    }

    return distances[destVertex] <= maxTravelDistance;
}

void binarySearch(int l, int r) {
    if (r < l) {
        return;
    }
    int mid = l + (r - l) / 2;
    if (pathExistsWithGivenWeight(mid)) {
        minWeight = mid;
        binarySearch(l, mid - 1);
    }
    else {
        binarySearch(mid + 1, r);
    }
}

int main() {
    int numVertices, numTunnels;
    cin >> numVertices >> numTunnels >> maxTravelDistance;

    tunnels.resize(numVertices);
    destVertex = numVertices - 1;
    int startVertex, maxWeight = INT_MIN;
    Tunnel tunnel;

    while (numTunnels--) {
        cin >> startVertex >> tunnel.endVertex >> tunnel.weightLimit >> tunnel.distance;
        startVertex--;
        tunnel.endVertex--;
        tunnels[startVertex].push_back(tunnel);
        maxWeight = max(tunnel.weightLimit, maxWeight);
    }

    binarySearch(0, maxWeight);

    cout << minWeight;

    return 0;
}