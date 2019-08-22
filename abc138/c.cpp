// C - Alchemist
// Sorting, Greedy
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long double> V(N,0.0L);
    for(auto &idx: V)
        cin >> idx;

    long double current = 0.0L;

    do {
        sort(V.begin(), V.end(), greater<int>());

        current = (V[V.size()-2]+V[V.size()-1])/2;

        V.pop_back();
        V.pop_back();

        V.push_back(current);
    } while(V.size() > 1);

    cout << V[0] << endl;

    return 0;
}
