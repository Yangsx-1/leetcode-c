class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> g(n);
        int m = edges.size();
        for (int i = 0; i < m; i++)
        {
            g[edges[i][0]].push_back({ edges[i][1], succProb[i] });
            g[edges[i][1]].push_back({ edges[i][0], succProb[i] });
        }
        vector<double> pro(n, 0);
        pro[start] = 1.0;
        priority_queue<pair<double, int>> heap;
        heap.push({ 1.0, start });
        while (heap.size())
        {
            auto ele = heap.top();
            heap.pop();
            int node = ele.second;
            double p = ele.first;
            if (node == end) break;
            for (auto x : g[node])
            {
                int nn = x.first;
                double pp = x.second;
                if (pp * p > pro[nn])
                {
                    pro[nn] = pp * p;
                    heap.push({ pro[nn], nn });
                }
            }
        }
        return pro[end];
    }
};
