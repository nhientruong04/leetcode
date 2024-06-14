class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        value_map = dict()
        bucket_map = [[] for _ in range (len(nums)+1)]

        for num in nums:
            # increase frequency of num
            if (num not in value_map.keys()):
                value_map[num] = 1
            else:
                value_map[num] += 1

        for num in value_map.keys():
            # append the num to the bucket map
            bucket_map[value_map[num]].append(num)
        
        ret = []
        
        for bucket in bucket_map[::-1]:
            val_ind = 0
            while val_ind<len(bucket):
                if k==0:
                    return ret

                ret.append(bucket[val_ind])
                val_ind+=1
                k-=1 

        return ret
            

if __name__ == "__main__":
    nums = [1,1,1,2,2,3]
    solution = Solution()
    ret = solution.topKFrequent(nums, 2)

    print(ret)