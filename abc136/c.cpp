// C - Build Stairs
// Greedy
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    long long int Hnow, Hlast;
    cin >> Hlast;
    Hlast--;

    for(int idx = 1LL; idx < N; idx++) {
        cin >> Hnow;

        if(Hnow > Hlast)
            --Hnow;

        if(Hnow < Hlast) {
            cout << "No" << endl;
            return 0;
        }

        Hlast = Hnow;
    }

    cout << "Yes" << endl;

    return 0;
}

