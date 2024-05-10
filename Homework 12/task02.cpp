#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const size_t MAX_SIZE = 2e5 + 5;

struct Edge {
    size_t from, to, index;
    int64_t cost, effort;

    bool operator<(const Edge& other) const {
        if (cost == other.cost) {
            return effort > other.effort;
        }
        else {
            return cost < other.cost;
        }
    }
};

Edge edges[MAX_SIZE];
size_t parents[MAX_SIZE];

size_t Find(size_t v) {
    if (v == parents[v])
        return v;

    return parents[v] = Find(parents[v]);
}

void Union(size_t x, size_t y) {
    parents[x] = parents[y];
}

void Kruskal(size_t n, size_t m) {
    sort(edges, edges + m);

    for (size_t i = 0; i <= n; i++) {
        parents[i] = i;
    }
    size_t root1, root2;
    for (size_t i = 0; i < m; i++) {
        root2 = Find(edges[i].from);
        root1 = Find(edges[i].to);
        if (root1 != root2) {
            cout << edges[i].index << '\n';
            Union(root1, root2);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, m;
    cin >> n >> m;

    for (size_t i = 0; i < m; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].cost >> edges[i].effort;
        edges[i].index = i + 1;
    }

    Kruskal(n, m);

    return 0;
}
