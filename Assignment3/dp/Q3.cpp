
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N; 
    cin >> N; 
    vector<int>result(N);
    for (int instance = 0; instance < N; instance++) {
        int K, M; 
        cin>>K>>M; 
        vector<int> weights(M);
        vector<int> values(M);
        for (int bage = 0; bage < M; bage++) {
            int A,B;
            cin>>A>>B; 
            weights[bage] = A;
            values[bage] = B;
        }
        vector<vector<int>> dp(M + 1, vector<int>(K + 1, 0));
        for (int i = 1; i <= M; ++i)
            for (int w = 1; w <= K; ++w)
                if (weights[i - 1] <= w)
                    dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
                else
                    dp[i][w] = dp[i - 1][w];
        result[instance]=dp[M][K];
    }
    for(int i=0;i<N;i++)
        cout << "Hey stupid robber, you can get " << result[i] << "." << endl;
    return 0;
}
