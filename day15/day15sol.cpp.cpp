class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total_sum =0;
        int max_ending_at =0;
        int min_ending_at= 0;
        int max_sum = INT_MIN;
        int min_sum= INT_MAX;
        
        for(int x: A){
            total_sum +=x;
            max_ending_at = max(max_ending_at + x,x);
            max_sum = max(max_ending_at, max_sum);
            min_ending_at = min(min_ending_at +x,x);
            min_sum = min(min_ending_at, min_sum);
        }
        if (max_sum >0)
            return max(max_sum, total_sum -min_sum);
        return max_sum;
    }
};
