#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef double dbl;



int main()
{
    FAST;
    pair<int,int> lastMax;
    lastMax.first=INT_MAX;
    int n, k, Max=0;
    cin>>n>>k;
    vector<int> a(n);
    vector<pair<int,pair<int,int>>> dp(n+1);
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(), a.end());
    for(int i=n-1;i>=0;i--){
        dp[i].first=a[i];
        dp[i].second.first=a[i]-k;
        dp[i].second.second=a[i]+k;
        if(dp[i].first<lastMax.first){
            Max+= dp[i].first;
            lastMax.first=dp[i].second.first;
            lastMax.second=dp[i].second.second;
        }
    }
    cout<<Max<<endl;
    return 0;
}
//here's a better sol:
/*
    sort(a.rbegin(), a.rend());

    set<int> excluded;  // To track excluded values
    int maxSum = 0;

    for (int i = 0; i < n; i++) {
        int x = a[i];

        // If x is not in the exclusion range, take it
        if (excluded.find(x) == excluded.end()) {
            maxSum += x;

            // Mark numbers in range [x-K, x+K] as excluded
            for (int j = x - k; j <= x + k; j++) {
                excluded.insert(j);
            }
        }
    }

    cout << maxSum << endl;
*/