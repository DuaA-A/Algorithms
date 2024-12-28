#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//using Tabulation
int LIS(int n, vector<int>& a) {
    vector<int> dp(n, 1);
    int maxx=1;
    for (int i = 1; i < n; i++) {
        for(int prev=0;prev<i;prev++)
            if (a[i] > a[prev])
                dp[i] = max(dp[i], dp[prev] + 1);
        maxx=max(maxx,dp[i]);
    }
    return maxx;
}

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    cout << LIS(n, a) << endl;
    return 0;
}
