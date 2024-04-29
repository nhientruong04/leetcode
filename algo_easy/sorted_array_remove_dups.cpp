#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    vector<int> unique_nums;
    int curr_num = nums[0];
    unique_nums.push_back(curr_num);
    int counter = 1;

    for (int i=1; i<nums.size(); i++) {
        if (nums[i] != curr_num) {
            unique_nums.push_back(nums[i]);
            curr_num = nums[i];
            counter++;
        }
    }

    nums.clear();

    for (int i=0; i<unique_nums.size(); i++) {
        nums.push_back(unique_nums[i]);
    }

    return counter;
}

int main() {
    vector<int> nums({1,1,2});

    cout << removeDuplicates(nums) << "\n";

    return 0;
}