// D - Summer Vacation
// Optimization, Sorting, Greedy, Priority Queue
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    const unsigned long long MAXN = 1e5+5;
    int N, M;
    cin >> N >> M;

    vector<vector<int>> jobs(MAXN);
    for(int idx = 0; idx < N; idx++) {
        int A, B;
        cin >> A >> B;
        
        // add a job that takes A days to complete
        // and rewards B
        jobs[A].push_back(B);
    }

    long long int ans = 0LL;

    // multiset is sorted
    // a priority queue would work too
    multiset<int, greater<int>, allocator<int>> available;

    // start from the M, go backwards
    // and take the best possible job
    for(int day = M - 1; day >= 0; day--) {
        // jobs that take M-day days to complete
        // ie. we can still take them
        for(int job: jobs[M - day])
            available.insert(job);

        if(!available.empty()) {
            // since multiset is sorted
            // we take the best job first
            ans += *available.begin();
            available.erase(available.begin());
        }
    }

    cout << ans << endl;

    return 0;
}

