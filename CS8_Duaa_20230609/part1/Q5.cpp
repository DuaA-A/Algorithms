#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include <cstring>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef double dbl;
using namespace std;

int main() {
    int N;
    // cout<<"Enter the length of the list A."<<endl;
    cin >> N;
    // cout<<"Enter the numbers in the list A separated by spaces."<<endl;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    vector<int> dp(N, 1);
    for (int i = 1; i < N; ++i) 
        for (int j = 0; j < i; ++j) 
            if (A[i] > A[j]) 
                dp[i] = max(dp[i], dp[j] + 1);  
    int lis_length = *max_element(dp.begin(), dp.end());
    // cout <<"the length  of the longest increasing subsequence in A= "<<lis_length << endl;
    cout<<lis_length<<endl;
    return 0;
}
