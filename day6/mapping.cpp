class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
            //by unordered mapping method
    unordered_map<int,int> counts;
        for(int n : nums){
            if (counts.find(n) == counts.end())
                counts.insert({n,1}); // if it does not exist then add it with a count of 1
            else
                counts[n] += 1;
            if(counts[n] > nums.size()/2)
                return n;
        }
        return -1;  // but won't be the case as array is non empty
    }
    
    
};