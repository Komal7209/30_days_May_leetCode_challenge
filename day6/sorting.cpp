class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        //by sorting 
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];  //so middle element would be majority element        
         }
    
    
};