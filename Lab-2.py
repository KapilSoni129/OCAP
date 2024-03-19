def count_paths(grid):
  n = len(grid)
  dp = [[0 for _ in range(n + 1)] for _ in range(n + 1)]

  for i in range(1, n + 1):
    for j in range(1, n + 1):
      if grid[i - 1][j - 1] == '#':
        dp[i][j] = 0
      else:
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % (1e9 + 7)

  return dp[n][n]

n = int(input())
grid = []
for _ in range(n):
  grid.append(list(input()))

num_paths = count_paths(grid)

print(num_paths)
