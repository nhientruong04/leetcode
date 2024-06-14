class Solution:
    def isPalindrome(self, s: str) -> bool:
        preprocess_list = [char.lower() for char in s if char.isalnum()]
        s = "".join(preprocess_list)
        i = 0
        j = len(s) - 1
        ret = True

        while (i<j):
            if s[i]==' ':
                i+=1
                continue
            elif s[j]==' ':
                j-=1
                continue

            if s[i] != s[j]:
                ret = False
                break

            i+=1
            j-=1
        
        return ret

if __name__ == "__main__":
    s = " "
    solution = Solution()
    ret = solution.isPalindrome(s)

    print(ret)