#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    if (nums.size()==1) {
        return false;
    }

    unordered_map <int, int> checkmap;

    for (int i=0; i<nums.size(); i++) {
        if (checkmap.find(nums[i]) != checkmap.end()) {
            return true;
        } else {
            checkmap[nums[i]] = 1;
        }
    }

    return false;
}

int main() {
    vector <int> nums {1,2,3,1};

    cout << containsDuplicate(nums) << endl;

    return 0;
}