class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        map = dict()

        for str in strs:
            key = ''.join(sorted(str))

            if key not in map.keys():
                map[key] = [str]
                continue;
            else:
                map[key].append(str)

        return [map[i] for i in map.keys()]
            

if __name__ == "__main__":
    strs = ["eat","tea","tan","ate","nat","bat"]
    solution = Solution()
    ret = solution.groupAnagrams(strs)

    print(ret)