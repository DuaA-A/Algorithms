#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include <cstring>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
 int maxt,m;
    bool first_case=true;

    while (cin>>maxt>>m) {
        int n;
        cin>>n;
        vector<int> depths(n + 1), golds(n + 1), timeCosts(n + 1);
        vector<vector<int>> dp(n + 1, vector<int>(maxt + 1, 0));
        for (int i = 1; i <= n; i++) {
            cin >> depths[i] >> golds[i];
            timeCosts[i] = 3 * m * depths[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= maxt; j++)
                if (timeCosts[i] <= j) 
                    dp[i][j] = max(dp[i - 1][j], golds[i] + dp[i - 1][j - timeCosts[i]]);
                else 
                    dp[i][j] = dp[i - 1][j];
        }
        vector<int> selectedTreasures;
        int remainingTime = maxt;
        int totalGold = dp[n][maxt];
        for (int i = n; i > 0; i--) {
            if (dp[i][remainingTime] != dp[i - 1][remainingTime]) {
                selectedTreasures.push_back(i);
                remainingTime -= timeCosts[i];
            }
        }
        if (!first_case) cout<<endl;
        first_case = false;
        cout << totalGold << endl;
        cout << selectedTreasures.size() << endl;
        for (int i = selectedTreasures.size() - 1; i >= 0; i--) {
            int idx = selectedTreasures[i];
            cout << depths[idx] << " " << golds[idx] << endl;
        }
    } 
}

int main(){
    FAST;
    int t=1;
    // cin>>t;
    while(t--)
    solve();
    return 0;
}