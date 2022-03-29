class Solution {
public:
    const int mod = 1000000007;
    struct worker
    {
	    int s;
	    int e;
    };
    static bool cmp(worker a, worker b)
    {
	    return a.e > b.e;
    }
    long long maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<worker> workers(n);
	    for (int i = 0; i < n; ++i)
	    {
		    workers[i].s = speed[i];
		    workers[i].e = efficiency[i];
	    }
        sort(workers.begin(), workers.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> que;
        long long sum = 0, ans = 0, eff = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            eff = workers[i].e;
            sum += workers[i].s;
            que.push(workers[i].s);
            if (--k < 0)
            {
                sum -= que.top();
                que.pop();
            }
            ans = max(ans, sum * eff);
	    }
        return ans % mod;
    }
};
