# Rotting Oranges (Leetcode)
# Leetcode Link : https://leetcode.com/problems/rotting-oranges/description/

# Time Complexity : O(row * col)
# Space Complexity : O(row * col)

from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        
        # Initialize a deque for BFS and a visited matrix
        que = deque()
        visited = [[0] * col for _ in range(row)]
        countFresh = 0  # To count the fresh oranges

        for i in range(row):
            for j in range(col):
                if grid[i][j] == 2:
                    que.append([i, j, 0])  # Append rotten orange's position and time 0
                    visited[i][j] = 2  # Mark the cell as visited
                else:
                    visited[i][j] = 0
                
                if grid[i][j] == 1:
                    # Increment fresh orange counter
                    countFresh += 1 

        time = 0  # To track the time taken to rot all oranges
        # Directions for the 4 possible adjacent cells (up, right, down, left)
        delRow = [-1, 0, 1, 0]
        delCol = [0, 1, 0, -1]
        count = 0  # To count the rotted fresh oranges

        # BFS to rot all adjacent fresh oranges
        while que:
            r = que[0][0]
            c = que[0][1]
            t = que[0][2]
            que.popleft()  # Remove the current cell from the queue
            time = max(time, t)  # Update the time with the maximum time value encountered

            for i in range(4):
                nrow = r + delRow[i]
                ncol = c + delCol[i]
                # If the adjacent cell is within bounds, is a fresh orange and hasn't been visited
                if 0 <= nrow < row and 0 <= ncol < col and visited[nrow][ncol] == 0 and grid[nrow][ncol] == 1:
                    # Append the new rotten orange to the queue with incremented time
                    que.append([nrow, ncol, t + 1])
                    # Mark the cell as visited
                    visited[nrow][ncol] = 2
                    # Increment the counter for rotted fresh oranges
                    count += 1
            
        # If the number of fresh oranges rotted doesn't match the initial fresh oranges count, return -1
        if countFresh != count:
            return -1
        
        return time
