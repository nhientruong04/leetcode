class Solution:
    def rob(self, nums: list[int]) -> int:
        if len(nums) < 3:
            return max(nums)

        dp_val_1 = [0, 0]
        dp_val_2 = [0, 0]

        for i in range(len(nums)-1):
            temp_val = dp_val_1[0]
            dp_val_1[0] = dp_val_1[1]
            dp_val_1[1] = max(temp_val + nums[i], dp_val_1[1])

        for i in range(1, len(nums)):
            temp_val = dp_val_2[0]
            dp_val_2[0] = dp_val_2[1]
            dp_val_2[1] = max(temp_val + nums[i], dp_val_2[1])


        return max(dp_val_1[-1], dp_val_2[-1])
    
if __name__ == "__main__":
    nums = [1,2,3,1]
    solution = Solution()
    ret = solution.rob(nums)

    print(ret)