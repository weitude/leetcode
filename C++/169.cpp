class Solution {
	public:
		int majorityElement(vector<int>& nums) {
			int cnt = 0, candidate = 0;
			for (int i = 0; i < nums.size(); i++) {
				if (cnt == 0) {
					candidate = nums[i];
					cnt++;
				} else if (nums[i] == candidate) {
					cnt++;
				} else {
					cnt--;
				}
			}
			return candidate;
		}
};

