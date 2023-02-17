class Solution
{
    public:
        vector<vector<int>> ans;
        bool used[10] = {};
        vector<int> cache;

        void DFS(vector<int> &nums, int idx)
        {
            if (idx == nums.size())
            {
                ans.push_back(cache);
                return;
            }
            for (int i = 0; i < nums.size(); i++)
            {
                if (!used[i])
                {
                    used[i] = true;
                    cache.push_back(nums[i]);
                    DFS(nums, idx + 1);
                    cache.pop_back();
                    used[i] = false;
                }
            }
        }

        vector<vector<int>> permute(vector<int> &nums)
        {
            DFS(nums, 0);
            return ans;
        }
};

