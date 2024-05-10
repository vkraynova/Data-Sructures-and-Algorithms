#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check(vector<size_t>& skills, size_t bestCase, size_t T) {
    size_t currentTeamsCount = 0;
    size_t currentSkillSum = 0;

    for (size_t i = 0; i < skills.size(); i++) {
        if (skills[i] + currentSkillSum > bestCase) {
            currentTeamsCount++;
            currentSkillSum = 0;
        }
        currentSkillSum += skills[i];
    }

    if (currentSkillSum != 0) {
        currentTeamsCount++;
    }

    return currentTeamsCount <= T;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t N, T;
    cin >> N >> T;

    vector<size_t> skills;

    size_t sum = 0;
    size_t maxSkill = 0;

    for (size_t i = 0; i < N; i++) {
        size_t skill;
        cin >> skill;
        sum += skill;
        if (skill > maxSkill) {
            maxSkill = skill;
        }

        skills.push_back(skill);
    }

    size_t bestCase = maxSkill;
    size_t low = bestCase;
    size_t high = sum;
    size_t result = 0;

    while (low <= high) {
        if (check(skills, bestCase, T)) {
            result = bestCase;
            high = bestCase - 1;
        }
        else {
            low = bestCase + 1;
        }

        bestCase = low + (high - low) / 2;
    }

    cout << result;

    return 0;
}