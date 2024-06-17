class Solution:
    def numIslands(self, grid: list[list[str]]) -> int:
        count = 0
        visited = [[0]*len(grid[0]) for _ in range(len(grid))]

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "0":
                    continue

                if visited[i][j]:
                    continue

                visit_queue = [(i,j)]

                while len(visit_queue) > 0:
                    k,v = visit_queue.pop(0)

                    if k<0 or k>=len(grid):
                        continue

                    if v<0 or v>=len(grid[0]):
                        continue

                    if grid[k][v] == "0":
                        continue

                    if visited[k][v]:
                        continue

                    visited[k][v] = 1

                    visit_queue.append((k-1, v))
                    visit_queue.append((k+1, v))
                    visit_queue.append((k, v-1))
                    visit_queue.append((k, v+1))
                
                count+=1

        return count


if __name__ == "__main__":
    grid = [["0","1","0"],["1","0","1"],["0","1","0"]] #3
    solution = Solution()
    res = solution.numIslands(grid)

    print(res)
