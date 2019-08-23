// E - Strings of Impurity
// Binary Search
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    vector<vector<int>> pos(26);

    // save all the appearances of s[idx]
    for(int idx = 0; idx < s.size(); ++idx)
        pos[s[idx] - 'a'].push_back(idx);

    long long ans = 0LL;
    int x = -1; // last match
    
    for(int idx = 0; idx < t.size(); ++idx) {
        int c = t[idx] - 'a';

        if(pos[c].empty()) {
            cout << -1 << endl;
            return 0;
        }

        // binary search for c
        // get the first appearance of c after the last match x
        int it = upper_bound(pos[c].begin(), pos[c].end(), x) - pos[c].begin();

        if(pos[c].size() == it) {
            // match was at the end
            ans += pos[c][0] - x + s.size();
            x = pos[c][0];
        } else {
            ans += pos[c][it] - x;
            x = pos[c][it];
        }
    }

    cout << ans << endl;

    return 0;
}

