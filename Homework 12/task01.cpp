#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int, vector<int>> graph;
unordered_map<int, pair<bool, int>> visited;
int componentCounter = 1;

void dfs(int v) {
    visited[v] = { true, componentCounter };
    for (auto w : graph[v]) {
        if (!visited[w].first) {
            dfs(w);
        }
    }
}

void traverse(int n) {
    for (int i = 1; i <= n; ++i) {
        if (!visited[i].first) {
            dfs(i);
            componentCounter++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, from, to, type;
    cin >> n >> m;

    while (m--) {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    cin >> k;
    traverse(n);

    while (k--) {
        cin >> type >> from >> to;
        if (type == 1) {
            cout << (visited[from].second == visited[to].second);
        }
        else {
            int oldComponent = visited[to].second;
            int newComponent = visited[from].second;
            for (int i = 1; i <= n; i++) {
                if (visited[i].second == oldComponent) {
                    visited[i].second = newComponent;
                }
            }
        }
    }

    return 0;
}
