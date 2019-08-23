// C - Green Bin
// Combinatorics, Map, Sorting
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;

    map<string, int> strings;
    for(int idx = 1; idx <= N; ++idx) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        strings[s] += 1;
    }

    long long int ans = 0LL;
    for(auto iter = strings.begin(); iter != strings.end(); ++iter) {
        long long int n = iter->second;
        ans += (n*(n-1LL))/2LL;
    }
    
    cout << ans << endl;

    return 0;
}

