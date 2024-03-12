MOD = 10**9 + 7

def count_dice_combinations(n):
  dp = [0] * (n + 1)  
  dp[0] = 1

  for i in range(1, n + 1):
    for j in range(1, min(7, i + 1)):  
      dp[i] = (dp[i] + dp[i - j]) % MOD  

  return dp[n]

def main():
  num_inputs = int(input())

  for _ in range(num_inputs):
    sum_value = int(input())

    result = count_dice_combinations(sum_value)
    print(result % MOD)

if __name__ == "__main__":
  main()
