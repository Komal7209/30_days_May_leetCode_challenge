class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bit_counts(num+1, 0);
        for(int i =1; i<= num; ++i)
            bit_counts[i] = bit_counts[i >> 1] + i%2;
        return bit_counts;
        
    }
};