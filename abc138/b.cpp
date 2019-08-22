// B - Resistors in Parallel
// Arithmetic
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N, A;
    long double inverse = 0.0L;
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> A;
        inverse += 1.0L/A;
    }
    cout << setprecision(10) << 1.0L/inverse << endl;
}
