def hamming_distance(x, y):
  xor = x ^ y  # XOR operation to find the different bits
  count = 0
  while xor:
    count += xor & 1  # Count the number of set bits in XOR
    xor >>= 1
  return count

def total_hamming_distance(nums):
  n = len(nums)
  total_distance = 0
  for i in range(n):
    for j in range(i + 1, n):
      total_distance += hamming_distance(nums[i], nums[j])
  return total_distance

num_elements = int(input("Enter the number of elements in the array: "))

nums = []

for i in range(num_elements):
  element = int(input("Enter element {}: ".format(i+1)))
  nums.append(element)

distance = total_hamming_distance(nums)
print("Total Hamming distance:", distance)
