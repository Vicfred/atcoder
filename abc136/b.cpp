//  B - Uneven Numbers 
//  IO
#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    int ans = 0;
    for(int i = 1; i <= N; ++i)
        if(to_string(i).size()%2 == 1)
            ++ans;

    cout << ans << endl;

    return 0;
}

