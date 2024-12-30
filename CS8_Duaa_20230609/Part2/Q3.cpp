#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <queue>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef double dbl;
using namespace std;

bool solve(int n, vector<vector<int>>& edges, int start, int end) {
    unordered_map<int, vector<int>> graph; 
    for (auto e : edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    vector<bool> visited(n, 0);
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == end) return true; 
        for (auto &node : graph[curr]) {
            if (!visited[node]) {
                visited[node] = 1; 
                q.push(node);
            }
        }
    }
    return false;
}

int main() {
    FAST;
    int t, n,m,start,end;
    cin >> t;
    while (t--) {
        cin>>n>>m>>start>>end; 
        vector<vector<int>> edges(m, vector<int>(2));
        for (int i=0;i<n;i++) 
            cin>>edges[i][0]>>edges[i][1]; 
        bool result = solve(n, edges, start, end);
        if (result)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
