// E - Coins Respawn
// Bellman-Ford
#include <iostream>
#include <vector>

using namespace std;

struct edge {
    int first, second;
    long long int cost;
};

int main() {
    const long long int INF = 1LL<<60;
    int N, M, P;
    cin >> N >> M >> P;

    vector<edge> edges(M);

    for(int idx = 0; idx < M; ++idx) {
        long long int A, B, C;
        cin >> A >> B >> C;

        // 0-based index
        edges[idx].first = A - 1;
        edges[idx].second = B - 1;

        // distribute the cost among the edges
        // instead of considering it at the end
        edges[idx].cost = P - C;
    }

    // Bellman-Ford
    vector<long long int> d(N, INF);
    d[0] = 0;

    for(int i = 0; i < 2*N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(d[edges[j].first] < INF) {
                if(d[edges[j].second] > d[edges[j].first] + edges[j].cost) {
                    if(i < N)
                        d[edges[j].second] =
                            max(-INF, min(INF, d[edges[j].first] + edges[j].cost));
                    else
                        d[edges[j].second] = -INF;
                }
            }
        }
    }

    if(-INF == d[N - 1])
        cout << -1 << endl;
    else
        cout << max(0LL, -d[N - 1]) << endl;

    return 0;
}

