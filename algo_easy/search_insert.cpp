#include <iostream>
#include <vector>

using namespace std;

int seachInsert(vector<int>& nums, int target) {
    int start_index = 0;
    int end_index = nums.size()-1;
    int return_index = -1;

    if (target < *nums.begin()) {
        return 0;
    }

    if (target > *(nums.end()-1)) {
        return nums.size();
    }

    while(start_index!=end_index && end_index-start_index!=1) {
        int pivot_index = start_index+(end_index-start_index)/2;
        int pivot_value = *(nums.begin()+pivot_index);

        if (target == pivot_value) {
            return_index = pivot_index;
            break;
        }

        if (target < pivot_value) {
            end_index = pivot_index;
        } else {
            start_index = pivot_index;
        }
    }

    if (return_index == -1) {
        return_index = start_index + 1;
    }

    return return_index;
}

int main() {
    vector<int> nums({1,3});

    cout << seachInsert(nums, 3) << "\n";

    return 0;
}