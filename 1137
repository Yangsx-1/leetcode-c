class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        else if(n == 1 || n == 2) return 1;
        else{
            vector<int> t = {0,1,1};
            for(int i=3; i<=n; ++i){
                int tmp = t[i-3] + t[i-2] + t[i-1];
                t.push_back(tmp);
            }
            return t[n];
        } 
    }
};
