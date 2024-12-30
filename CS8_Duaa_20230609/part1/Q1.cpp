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
    int n, totalSum=0, minn=501;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        totalSum+=a[i];
    }
    vector<bool> dp(totalSum/2 + 1,false);
    dp[0]=true;
    for(int c=0;c<n;c++)
        for(int s = totalSum / 2; s >= a[c]; s--)
            dp[s] = dp[s] || dp[s - a[c]];

    for(int s=totalSum/2;s>=0;s--){
        //cout<<minn<<" ";
        if(dp[s]){
            minn = abs(totalSum - 2*s);
            break;
        }
    }
    cout<<minn<<endl;
}

int main(){
    FAST;
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}