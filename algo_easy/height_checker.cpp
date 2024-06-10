#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int heightChecker(vector<int>& heights) {
    if (heights.size() == 1) {
        return 0;
    }

    vector<int> heights_copy;
    heights_copy = heights;
    sort(heights_copy.begin(), heights_copy.end());

    int counter = 0;

    for (int i=0; i<heights.size(); i++) {
        if (heights[i] != heights_copy[i]) {
            counter++;
        }
    }

    return counter;
}

int main() {
    vector<int> heights {1,1,4,2,1,3};

    cout << heightChecker(heights) << endl;

    return 0;
}