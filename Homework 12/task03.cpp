#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct Edge {
    size_t from, to, speed;

    bool operator<(const Edge& other) const {
        return speed < other.speed;
    }
};

const size_t MAX_SIZE = 100000;
Edge edges[MAX_SIZE];
size_t parent[MAX_SIZE];
size_t depth[MAX_SIZE];

size_t Find(size_t x) {
    if (x == parent[x])
        return x;

    return parent[x] = Find(parent[x]);
}

bool Union(size_t x, size_t y) {
    size_t root1 = Find(x);
    size_t root2 = Find(y);

    if (root1 == root2) {
        return false;
    }
    if (depth[root1] > depth[root2]) {
        swap(root1, root2);
    }
    if (depth[root1] == depth[root2]) {
        depth[root2]++;
    }
    parent[root1] = root2;

    return true;
}

void initializeParents(size_t n) {
    for (size_t j = 0; j <= n; j++) {
        parent[j] = j;
    }
}

void kruskal(size_t n, size_t m) {
    sort(edges, edges + m);
    size_t minV = 0;
    size_t maxV = ULLONG_MAX;

    for (size_t i = 0; i < m; i++) {
        initializeParents(n);

        size_t count = 0;
        size_t currMin = edges[i].speed;
        size_t currMax = edges[i].speed;
        size_t diff = maxV - minV;

        for (size_t j = i; j < m; j++) {
            if (Union(edges[j].from, edges[j].to)) {
                count++;
                currMax = max(currMax, edges[j].speed);
            }
            if (diff <= currMax - currMin)
                break;
        }
        if (count != n - 1 || diff <= currMax - currMin)
            continue;

        minV = currMin;
        maxV = currMax;
    }
    cout << minV << " " << maxV;
}

int main() {

    size_t n, m;
    cin >> n >> m;
    for (size_t i = 0; i < m; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].speed;

    }
    kruskal(n, m);
    return 0;
}
