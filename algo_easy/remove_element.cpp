#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int k = -1;
    int i = 0;

    while (i<nums.size()) {
        if (nums[i] == val) {
            if (k==-1) {
                k = i;
            }

            nums[i] = -1;
        } else if (nums[i] != val) {
            if (k>-1 && k<i) {
                nums[k] = nums[i];
                k++;
            }
        }

        i++;
    }

    if (k==-1) {
        return nums.size();
    } else {
        return k;
    }
}

int main() {
    vector<int> nums {0,1,2,2,3,0,4,2};
    int val = 2;

    cout << removeElement(nums, val) << endl;

    return 0;
}