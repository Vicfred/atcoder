// D - Gathering Children
// Greedy
#include <iostream>
#include <string>

using namespace std;

const unsigned long long int MAXN = 1000001L;
int preffix_L[MAXN], preffix_R[MAXN], suffix_L[MAXN], suffix_R[MAXN], ans[MAXN];

int main() {
    string S;
    cin >> S;
    int N = S.size();

    // sum of preffixes
    for(int i = 0; i < N; ++i) {
        if('L' == S[i]) {
            preffix_L[i] = preffix_L[i-1]+1;
            preffix_R[i] = 0;
        } else {
            preffix_R[i] = preffix_R[i-1]+1;
            preffix_L[i] = 0;
        }
    }

    // sum of suffixes
    for(int i = N; i >= 0; --i) {
        if('L' == S[i]) {
            suffix_L[i] = suffix_L[i+1]+1;
            suffix_R[i] = 0;
        } else {
            suffix_R[i] = suffix_R[i+1]+1;
            suffix_L[i] = 0;
        }
    }

    for(int i = 0; i < N-1; ++i) {
        if('R' == S[i] and 'L' == S[i+1]) {
            ans[i] = (preffix_R[i]+1)/2 + suffix_L[i+1]/2;
            ans[i+1] = preffix_R[i]/2 + (suffix_L[i+1]+1)/2;
        }
    }

    for(int i = 0; i < N; ++i)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}

