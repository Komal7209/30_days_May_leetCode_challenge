class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        x = nums[0]
        
        for i in range(1, len(nums)):
            x=x^nums[i]
            
        return x 