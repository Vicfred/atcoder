//  A - Transfer
//  IO
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    A -= B;
    C -= A;

    cout << max(0,C) << endl;

    return 0;
}

