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
		vector<vector<int>> levelOrder(TreeNode* root) {
			vector<vector<int>> ans;
			traversal(root, ans, 0);
			return ans;
		}

		void traversal(TreeNode* root, vector<vector<int>> &ans, int depth) {
			if (!root)
				return;
			traversal(root->left, ans, depth + 1);
			traversal(root->right, ans, depth + 1);
			while (ans.size() <= depth)
				ans.push_back({});
			ans[depth].push_back(root->val);
		}
};


