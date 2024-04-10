def largest_number(nums):
  nums.sort()

  if nums[0] == 0 and len(nums) > 1:
    return "0"

  largest_num = ""
  for num in nums:
    largest_num += str(num)

  return largest_num

num_elements = int(input("Enter the number of elements: "))
nums = []
for i in range(num_elements):
  element = int(input("Enter element {}: ".format(i+1)))
  nums.append(element)

# Call the function to find the largest number
largest_number_str = largest_number(nums)

print("The largest number that can be formed is:", largest_number_str)
