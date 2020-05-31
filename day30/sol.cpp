//using heap


struct ComparePoints{
    bool operator()(const vector <int>& p1, const vector<int>& p2){
        return (p1[0]*p1[0] + p1[1]*p1[1]) < (p2[0]*p2[0] + p2[1]*p2[1]);
    }
};


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, ComparePoints> pq;
        for(vector<int>& pt : points){
            if(pq.size() < K)
                pq.push(pt);
            else{
                const vector <int>& top = pq.top();
                int d1 = top[0]* top[0] + top[1]*top[1];
                int d2 = pt[0]* pt[0] + pt[1]*pt[1];
                if (d1 > d2){
                    pq.pop();
                    pq.push(pt);
                }
            }
        }
        
        vector<vector<int>> result;
        while(!pq.empty()){
            result.push_back(pq.top());
            pq.pop();
        }
        
        return result;
        
    }
};