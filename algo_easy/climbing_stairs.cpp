#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
    vector <int> counters (n, 1);

    for (int i=1; i<counters.size(); i++) {
        if (i==1) {
            counters[i] = 2;
            continue;
        }

        int curr_count = 0;

        // if step 2 steps
        if (i-2>=0) {
            curr_count += counters[i-2];
        }

        // if step 1 step
        curr_count += counters[i-1];

        counters[i] = curr_count;
    }

    return counters[n-1];
}

int main() {
    int n = 3;

    cout << climbStairs(n) << endl;

    return 0;
}