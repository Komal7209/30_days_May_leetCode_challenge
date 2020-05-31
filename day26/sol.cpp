class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        
        unordered_map<int, int> cache;   //(sum, index)
        int count = nums[0] ==1 ? 1: -1;
        
        cache[0] = -1;
        cache[count] =0;
        int _max =0;
        
        for(int i= 1; i< nums.size(); ++i){
            count =(nums[i] ==1) ? count + 1: count -1;
            
            if(cache.find(count) != cache.end()) // found
                _max  = max(_max, i- cache[count]);
            else
                cache[count]= i;
            
        }
        return _max;
    }
};