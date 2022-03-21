class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> maxtem(temperatures.size());
        int j = 0;
        for(int i=0; i<temperatures.size()-1; ++i){
            s.push(i);
            while(!s.empty() && temperatures[s.top()] < temperatures[i+1]){
                maxtem[s.top()] = i+1-s.top();
                s.pop();
            }
        }
        return maxtem;
    }
};
