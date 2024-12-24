#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int W, const vector<int>& weights, const vector<int>& profits) {
    int n = weights.size();
    vector<vector<int>> m(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) 
        for (int w = 0; w <= W; ++w) 
            if (weights[i - 1] <= w) 
                m[i][w] = max(m[i - 1][w], m[i - 1][w - weights[i - 1]] + profits[i - 1]);
            else 
                m[i][w] = m[i - 1][w];
    return m[n][W];
}

int main() {
    int W; 
    cout << "enter the maximum w: ";
    cin >> W;
    int n;
    cout << "enter n: ";
    cin >> n;
    vector<int> weights(n), profits(n);
    cout << "enter the weights of the items: ";
    for (int i = 0; i < n; ++i) cin >> weights[i];

    cout << "enter the profits: ";
    for (int i = 0; i < n; ++i) cin >> profits[i];

    int maxValue = knapsack(W, weights, profits);
    cout << "the maximum valu: " << maxValue << endl;

    return 0;
}
