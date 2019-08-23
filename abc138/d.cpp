// D - Ki
// DFS
#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

// DFS on tree
void count(vector<int> &counter, map<int, unordered_set<int>> &edges, int number) {
    int v = counter[number];

    for(auto child: edges[number]) {
        counter[child] += v;
        edges[child].erase(number);
        count(counter, edges, child);
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;

    map<int, unordered_set<int>> edges;

    for(int i = 1; i < N; ++i) {
        int a, b;
        cin >> a >> b;

        edges[a].insert(b);
        edges[b].insert(a);
    }

    vector<int> counter(N+1);
    for(int i = 1; i <= Q; ++i) {
        int p, x;
        cin >> p >> x;

        counter[p] += x;
    }

    count(counter, edges, 1); // DFS the root

    for(int i = 1; i <= N; ++i)
        cout << counter[i] << " ";
    cout << endl;
    return 0;
}

