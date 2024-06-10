#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if (nums.size() == 1) {
        return 1;
    }

    int curr_length = 0;
    vector <int> dp_length {nums[0]};

    for (int i=1; i<nums.size(); i++) {
        int length_index = dp_length.size()-1;

        while (length_index >= 0) {

            if (nums[i] > dp_length[length_index]) {
                // new length
                if (length_index+1>dp_length.size()-1) {
                    dp_length.push_back(nums[i]);
                } else {
                    // if current value is smaller than value of the next length
                    dp_length[length_index+1] = min(dp_length[length_index+1], nums[i]);
                }
            } else {
                if (length_index==0 && nums[i]<dp_length[length_index]) {
                    dp_length[length_index] = nums[i];
                }
            }

            length_index--;
        }
    }
    
    return dp_length.size();
}

int main() {
    vector <int> nums {7,7,7,7,7,7,7};

    cout << lengthOfLIS(nums) << endl;

    return 0;
}