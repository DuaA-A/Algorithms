#include<iostream>
#include<algorithm>
#include<vector>  
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> G(n), S(m);
    for (int i = 0; i < n; i++) {
        cin >> G[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> S[i];
    }
    sort(G.begin(), G.end());
    sort(S.begin(), S.end());
    int chi_num = 0;  
    int cok_num = 0;  
    int countmaxchi = 0;  
    while (chi_num < n && cok_num < m) {
        if (S[cok_num] >= G[chi_num]) {
            countmaxchi++;  
            chi_num++;  
        }
        cok_num++;  
    }
    cout << countmaxchi << endl;
    return 0;
}
