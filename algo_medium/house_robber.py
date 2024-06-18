class Solution:
    def rob(self, nums: list[int]) -> int:
        if len(nums) < 3:
            return max(nums)

        dp_val = [0, 0]

        for i in range(len(nums)):
            temp_val = dp_val[0]
            dp_val[0] = dp_val[1]
            dp_val[1] = max(temp_val + nums[i], dp_val[1])

        return max(dp_val)

if __name__ == "__main__":
    nums = [1,2,3,1]
    solution = Solution()
    ret = solution.rob(nums)

    print(ret)