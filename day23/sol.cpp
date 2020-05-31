class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        vector<vector <int>> result;
        int i = 0;
        int j = 0;
        while( i< A.size() && j< B.size()){
            vector<int>a=A[i];
            vector<int>b=B[j];
            if(a[1] < b[0]) i++;
            else if (b[1] < a[0]) j++;
            else{ //overlap
                int start = max(a[0], b[0]);
                int end = min(a[1], b[1]);
                result.push_back({start,end});
                if(a[1] < b[1]) i++;
                else if(a[1] > b[1]) j++;
                else{
                    i++;
                    j++;
                }
                
            }
            
        }
        return result;
        
        
    }
};