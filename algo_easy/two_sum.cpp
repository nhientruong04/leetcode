#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map <int, int> sum_map;
    vector<int> ret;

    for (int i=0; i<nums.size(); i++) {
        sum_map[target-nums[i]] = i;
    }

    for (int i=0; i<nums.size(); i++) {
        if (sum_map.find(nums[i]) != sum_map.end()) {
            if (sum_map[nums[i]] == i) {
                continue;
            }

            int residual_num = sum_map[nums[i]];
            ret.push_back(residual_num);
            ret.push_back(i);

            break;
        }
    }

    return ret;
}

int main() {
    return 0;
}