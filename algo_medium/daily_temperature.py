class Solution:
    def dailyTemperatures(self, temperatures: list[int]) -> list[int]:
        if len(temperatures) == 1:
            return [0]

        res = [0] * len(temperatures)
        compare_stack = [(temperatures[-1], len(temperatures)-1)]
        i = len(temperatures) - 2

        while i>=0:

            # if current temp is smaller than the top()
            if temperatures[i] < compare_stack[-1][0]:
                res[i] = compare_stack[-1][1] - i
                compare_stack.append((temperatures[i], i))
            else:
                # loop and pop until find a greater temp
                while len(compare_stack) != 0:
                    curr_node = compare_stack[-1]
                    
                    if curr_node[0] > temperatures[i]:
                        res[i] = curr_node[1] - i
                        break
                    else:
                        compare_stack.pop()

                compare_stack.append((temperatures[i], i))

            i-=1

        return res

if __name__ == "__main__":
    temperatures = [89,62,70,58,47,47,46,76,100,70]
    solution = Solution()
    ret = solution.dailyTemperatures(temperatures)

    print(ret)