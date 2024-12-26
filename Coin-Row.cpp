#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int f(int i, vector<int>nums, vector<int> & dp){
    if(1==0) return dp[0];
    if(i<0) return 0;
    if(dp[i]!=0) return dp[i];

    int pick=nums[i] + f(i-2,nums,dp);
    int notPick = 0 + f(i-1,nums,dp);

    return max(pick,notPick);
}

int main() {
    int n, target;
    cout<<"enter no.of numbers: ";
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    vector<int> dp(n+1,0);
    cout<<f(n-1,nums,dp)<<endl;
    return 0;
}
