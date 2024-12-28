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
