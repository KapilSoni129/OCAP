def max_ice_cream_bars(costs, coins):
  """
  Finds the maximum number of ice cream bars the boy can buy with the given coins.

  Args:
      costs: A list of integers representing the price of each ice cream bar in coins.
      coins: An integer representing the number of coins the boy has.

  Returns:
      The maximum number of ice cream bars the boy can buy.
  """

  # Sort the costs in ascending order.
  costs.sort()

  # Initialize a counter for the number of ice cream bars the boy can buy.
  num_bars = 0

  # Iterate through the costs list.
  for cost in costs:
    # If the current cost is less than or equal to the remaining coins,
    # increment the counter and subtract the cost from the remaining coins.
    if cost <= coins:
      num_bars += 1
      coins -= cost
    # If the remaining coins are not enough to buy the current ice cream bar,
    # break the loop.
    else:
      break

  # Return the maximum number of ice cream bars the boy can buy.
  return num_bars

# Get user input for number of ice cream bars and their costs
num_bars = int(input("Enter the number of ice cream bars: "))
costs = []
for i in range(num_bars):
  cost = int(input("Enter the cost of ice cream bar {} (in coins): ".format(i+1)))
  costs.append(cost)

# Get user input for the number of coins
coins = int(input("Enter the number of coins the boy has: "))

# Call the function to find the maximum number of bars
output = max_ice_cream_bars(costs, coins)

print("The maximum number of ice cream bars the boy can buy is:", output)
