class Solution
{
    public:
        vector<string> ans;
        int N;

        void DFS(int l, int r, string s)
        {
            if (l > N || r > l || r > N)
                return;
            if (l == N && r == N)
            {
                ans.push_back(s);
                return;
            }
            DFS(l + 1, r, s + '(');
            DFS(l, r + 1, s + ')');
        }

        vector<string> generateParenthesis(int n)
        {
            N = n;
            DFS(0, 0, "");
            return ans;
        }
};

