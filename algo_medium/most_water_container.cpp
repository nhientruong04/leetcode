#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
    int max_amount = 0;

    int left_ptr = 0;
    int right_ptr = height.size()-1;

    while (left_ptr < right_ptr) {
        int curr_height = (height.at(left_ptr) < height.at(right_ptr)) ? height.at(left_ptr) : height.at(right_ptr);

        if (curr_height*(right_ptr-left_ptr) > max_amount) {
            max_amount = curr_height*(right_ptr-left_ptr);
        }

        if (height.at(left_ptr)<=height.at(right_ptr)) {
            left_ptr++;
        } else {
            right_ptr--;
        }
    }

    return max_amount;
}

int main() {
    vector<int> containers {1,8,6,2,5,4,8,3,7};
    // vector<int> containers {0, 0};

    cout << maxArea(containers) << "\n";

    return 0;
}