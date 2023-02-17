/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
	public:
		vector<vector<int>> ans;
		vector<pair<int, int>> cache;
		int h = -1;

		void traversal(TreeNode *root, int level)
		{
			if (!root)
			{
				if (h < level)
					h = level;
				return;
			}
			traversal(root->left, level + 1);
			cache.push_back({level, root->val});
			traversal(root->right, level + 1);
		}

		vector<vector<int>> levelOrder(TreeNode* root) {
			if (!root)
				return ans;
			traversal(root, 0);
			ans.resize(h);
			for (auto p : cache)
				ans[p.first].push_back(p.second);
			return ans;
		}
};

