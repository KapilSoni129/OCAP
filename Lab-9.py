def min_patches(nums, n):
  miss = 1
  patches = 0
  i = 0
  
  while miss <= n:
    if i < len(nums) and nums[i] <= miss:
      miss += nums[i]
      i += 1
    else:
      patches += 1
      miss += miss

  return patches

nums = []
while True:
  num_str = input("Enter a number (or 'done' to finish): ")
  if num_str == 'done':
    break
  try:
    num = int(num_str)
    nums.append(num)
  except ValueError:
    print("Invalid input. Please enter an integer.")

nums.sort()  

try:
  n = int(input("Enter the value of n: "))
except ValueError:
  print("Invalid input. Please enter an integer.")
else:
  result = min_patches(nums, n)
  print(f"Minimum number of patches required: {result}")
