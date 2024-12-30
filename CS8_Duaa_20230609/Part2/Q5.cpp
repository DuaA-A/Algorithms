#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <random>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef vector<pair<int, int>> vpi;
typedef vector<vpi> vvpi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const long long mod = 1000000007;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(c) (c).begin(),(c).end()
#define sz(c) static_cast<int>((c).size())
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

const int MAXN = 100000;
vector<int> lst[MAXN];
int parent[MAXN];

void make_set(int v) {
    lst[v] = vector<int>(1, v);
    parent[v] = v;
}

int find_set(int v) {
    return parent[v];
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (lst[a].size() < lst[b].size())
            swap(a, b);
        while (!lst[b].empty()) {
            int v = lst[b].back();
            lst[b].pop_back();
            parent[v] = a;
            lst[a].push_back(v);
        }
    }
}

vvpi nb;
vi ans(200100, 0);
vi used;
int n, m;

int dfs(int v) {
    used[v] = 1;
    int ssz = 1;
    for (auto u : nb[v]) {
        if (used[u.first]) continue;

        ll st = dfs(u.first);
        ssz += st;

        ll r = st * (n - st);
        int cur = u.second;
        while (r > 0) {
            if (r % 2) ans[cur]++;
            r /= 2;
            if (ans[cur] == 2) {
                ans[cur] = 0;
                r++;
            }
            cur++;
        }
    }
    return ssz;
}

int main() {
    FAST;
    vector<pair<int, pi>> e;
    cin >> n >> m;
    forn(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        e.pb(mp(c, mp(a - 1, b - 1)));
    }
    nb.resize(n);
    forn(i, 0, n) make_set(i);
    sort(all(e));

    for (auto u : e) {
        int a = u.second.first;
        int b = u.second.second;
        int x = find_set(a);
        int y = find_set(b);
        if (x == y) continue;
        int c = u.first;
        nb[a].pb(mp(b, c));
        nb[b].pb(mp(a, c));
        union_sets(a, b);
    }
    used = vi(n, 0);
    dfs(0);
    while (ans.back() == 0) ans.pop_back();
    reverse(all(ans));
    for (auto x : ans) cout << x;
    cout << "\n";
    return 0;
}
