#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 4000;
int M[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int n;

struct Region {
    int minX, minY, maxX, maxY, area;
    Region() : minX(0), minY(0), maxX(0), maxY(0), area(0) {}
    Region(int minX, int minY, int maxX, int maxY, int area)
        : minX(minX), minY(minY), maxX(maxX), maxY(maxY), area(area) {}
};

bool isValid(int x, int y, int n) {
    return (x >= 0 && x < n&& y >= 0 && y < n);
}

bool compare(const Region& a, const Region& b) {
    return a.area > b.area;
}


void dfs(int x, int y, int n, Region& region) {
    if (!isValid(x, y, n) || M[x][y] == 0 || visited[x][y])
        return;

    visited[x][y] = true;
    region.area++;
    region.minX = min(region.minX, x);
    region.minY = min(region.minY, y);
    region.maxX = max(region.maxX, x);
    region.maxY = max(region.maxY, y);

    int dx[] = { 0, 0, 1, -1 };
    int dy[] = { 1, -1, 0, 0 };

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        dfs(newX, newY, n, region);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
            visited[i][j] = false;
        }
    }

    vector<Region> regions;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (M[i][j] && !visited[i][j]) {
                Region region(i, j, i, j, 0);
                dfs(i, j, n, region);
                regions.push_back(region);
            }
        }
    }

    sort(regions.begin(), regions.end(), compare);

    for (const auto& region : regions) {
        int regionWidth = region.maxX - region.minX + 1;
        int regionHeight = region.maxY - region.minY + 1;
        cout << regionWidth * regionHeight << " ";
    }

    return 0;
}