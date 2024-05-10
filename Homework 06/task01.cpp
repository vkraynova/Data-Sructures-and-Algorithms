#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct Node {
    int val;
    Node* left;
    Node* right;
};

Node nodes[1000000];
int n, l, r, a;

long long sum[2000000] = { 0 };
int minIndex = 1000000;
int maxIndex = 1000000;

void sumColumns(Node* root, int index) {
    if (root == nullptr) {
        return;
    }
    sum[index] += root->val;

    if (index < minIndex) {
        minIndex = index;
    }
    if (maxIndex < index) {
        maxIndex = index;
    }
    sumColumns(root->left, index - 1);
    sumColumns(root->right, index + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> l >> r;
        nodes[i].val = a;

        if (l != -1) {
            nodes[i].left = &nodes[l];
        }
        else {
            nodes[i].left = nullptr;
        }

        if (r != -1) {
            nodes[i].right = &nodes[r];
        }
        else
            nodes[i].right = nullptr;
    }

    sumColumns(&nodes[0], minIndex);

    for (int i = minIndex; i <= maxIndex; i++) {
        if (sum[i] != 0)
            cout << sum[i] << " ";
    }

}