#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include <cstring>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef double dbl;
using namespace std;

void solve(){
    int t, w, n; 
    cin>>t>>w>>n; 
    vector<int> depths(n), golds(n), timeCosts(n);
    for (int i=0; i<n; ++i) {
        cin>>depths[i]>>golds[i];
        timeCosts[i]=3*w*depths[i];  
    }
    vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));
    for (int i=1; i<=n; ++i) {
        for (int remainT=0; remainT<=t; remainT++) 
            if (timeCosts[i-1]<=remainT) 
                dp[i][remainT] = max(dp[i-1][remainT], dp[i-1][remainT-timeCosts[i-1]]+golds[i-1]);
            else 
                dp[i][remainT]=dp[i-1][remainT];
    }
    vector<pair<int, int>> ans;
    int remainingTime = t;
    for (int i = n; i > 0; --i) {
        if (dp[i][remainingTime] != dp[i - 1][remainingTime]) {
            ans.emplace_back(depths[i - 1], golds[i - 1]);
            remainingTime -= timeCosts[i - 1];
        }
    }
    cout<<dp[n][t]<<endl;                        
    cout<<ans.size()<<endl;        
    for (auto it = ans.rbegin(); it!=ans.rend(); ++it) 
        cout<<it->first<<" "<<it->second<<endl; 
}

int main(){
    FAST;
    int t=1;
    // cin>>t;
    while(t--)
        solve();
    return 0;
}