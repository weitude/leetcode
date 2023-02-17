class Solution
{
    public:
        vector<vector<int>> vvi;
        vector<int> cache;

        void solve(vector<int> &candidates, int idx, int target)
        {
            if (idx >= candidates.size())
                return;
            if (target == 0)
            {
                vvi.push_back(cache);
                return;
            }
            if (target >= candidates[idx])
            {
                cache.push_back(candidates[idx]);
                solve(candidates, idx, target - candidates[idx]);
                cache.pop_back();
            }
            solve(candidates, idx + 1, target);
        }

        vector<vector<int>> combinationSum(vector<int> &candidates, int target)
        {
            solve(candidates, 0, target);
            return vvi;
        }
};

