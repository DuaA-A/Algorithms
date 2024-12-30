#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include <cstring>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef double dbl;
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int chi_num = 0, cok_num = 0, countmaxchi = 0;  
    while (chi_num < g.size() && cok_num < s.size()) {
        if (s[cok_num] >= g[chi_num]) {
            countmaxchi++; 
            chi_num++;  
        }
        cok_num++;  
    }
    return countmaxchi;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> g(n), s(m);
    for (int i = 0; i < n; i++)
        cin >> g[i];  
    for (int i = 0; i < m; i++) 
        cin >> s[i];  
    cout << findContentChildren(g, s) << endl;
    return 0;
}