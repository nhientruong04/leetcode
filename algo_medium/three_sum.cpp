#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end()); 

    int i = 0;
    while (nums.at(i)<=0 && i+2 < nums.size()) {
        if (i>0 && nums.at(i)==nums.at(i-1)) {
            i++;
            continue;
        }

        int j = i+1;
        int k = nums.size() - 1;

        while (j<k) {
            int sum = nums.at(i) + nums.at(j) + nums.at(k);

            if (sum == 0) {
                vector<int> new_set = {nums.at(i), nums.at(j), nums.at(k)};
                result.push_back(new_set);

                j++;
                while (nums.at(j) == nums.at(j-1) && j<k) {
                    j++;
                }
            }

            if (sum > 0) {
                k--;
            }

            if (sum < 0) {
                j++;
            }
        }

        i++;
    }

    return result;
}

int main() {
    // vector<int> nums = {-1,0,1,2,-1,-4};
    vector<int> nums = {0, 0, 0, 0};

    threeSum(nums);

    return 0;
}