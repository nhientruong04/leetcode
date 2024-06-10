#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
    if (nums.size()==1) {
        return true;
    }

    int curr_step = nums.size()-1;

    for (int i=curr_step-1; i>=0;i--) {
        if (nums[i]>=curr_step-i) {
            curr_step = i;
        }
    }

    return true ? curr_step==0 : false;
}

int main() {
    vector <int> nums {3,2,1,0,4};

    cout << canJump(nums) << endl;

    return 0;
}