#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Time {
    int beg;
    int end;
    int members;

    Time() : beg(0), end(0), members(0) {}

    Time(int beg, int end, int members) : beg(beg), end(end), members(members) {}
};

struct CompareTime {
    bool operator()(const Time& t1, const Time& t2) {
        if (t1.end == t2.end) {
            return t1.beg < t2.beg;
        }
        return t1.end > t2.end;
    }
};

int main() {
    int queries;
    cin >> queries;

    for (int i = 0; i < queries; i++) {
        int groups, capacity;
        cin >> groups >> capacity;

        vector<Time> v(groups);
        for (int j = 0; j < groups; j++) {
            int b, e, m;
            cin >> m >> b >> e;
            Time t(b, e, m);
            v[j] = t;
        }

        sort(v.begin(), v.end(), [](const Time& t1, const Time& t2) {
            return t1.beg < t2.beg;
            });

        priority_queue<Time, vector<Time>, CompareTime> q;

        int currentMembers = 0;
        bool hasMoreMembers = false;

        for (int i = 0; i < groups; i++) {
            Time t = v[i];

            while (!q.empty() && q.top().end <= t.beg) {
                currentMembers -= q.top().members;
                q.pop();
            }

            if (currentMembers + t.members > capacity) {
                hasMoreMembers = true;
                break;
            }

            q.push(t);
            currentMembers += t.members;
        }

        cout << (hasMoreMembers ? 0 : 1) << "\n";
    }
    return 0;
}
