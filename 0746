class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> mincost = {0,0};
        int top = cost.size();
        for(int i=2; i<=top; ++i){
            int c1 = mincost[i-2] + cost[i-2];
            int c2 = mincost[i-1] + cost[i-1];
            int min = c1<c2 ? c1:c2;
            mincost.push_back(min);
        }
        return mincost[top];
    }
};
