class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        vector<int> trust_count(N,0);
        for(vector<int> t: trust){
            trust_count[t[0]-1]--;
            trust_count[t[1]-1]++;
        }
        
        int result =-1;
        for(int i=0; i<N; ++i){
            if(trust_count[i]==N-1)
                return i+1;
        }
        return result;
    }
    
};