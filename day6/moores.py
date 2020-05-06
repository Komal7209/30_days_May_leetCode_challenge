class Solution:
    def majorityElement(self, nums: List[int]) -> int:
           #moores voting algorithm
            
            
        idx =0
        count =1
        for i in range(1, len(nums)):
            if(nums[i] == nums[idx]):       #idx is candidate
                count+=1
            else:
                count-=1
            if(count == 0):              #reset candidate
                idx =i                  # we reset new index to be the current index
                count =1              #so that ir resets to original count 
          
        return nums[idx]                 # the candidate is returned