class Solution:
    def twoSum(self, nums, target):
    	record = {}
    	for i in range(len(nums)):
    		if nums[i] in record.keys():
    			return [record[nums[i]], i]
    		record.update({target - nums[i] : i})

nums = [3, 4, 8, 20, 11]
target = 14

sol = Solution()
print(sol.twoSum(nums, target))