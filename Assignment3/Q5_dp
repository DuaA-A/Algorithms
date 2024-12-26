using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    cout<<"Enter the length of the list A."<<endl;
    cin >> N;
    cout<<"Enter the numbers in the list A separated by spaces."<<endl;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    
    vector<int> dp(N, 1);
    
    for (int i = 1; i < N; ++i) 
        for (int j = 0; j < i; ++j) 
            if (A[i] > A[j]) 
                dp[i] = max(dp[i], dp[j] + 1);  
    
    int lis_length = *max_element(dp.begin(), dp.end());
    cout <<"the length  of the longest increasing subsequence in A= "<<lis_length << endl;
    return 0;
}
