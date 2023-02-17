class Solution
{
    public:
        int minIndex(vector<int> &nums)
        {
            if (nums.size() == 1)
                return 0;
            int left = 0, right = nums.size() - 1;
            if (nums[left] < nums[right])
                return 0;
            while (left < right)
            {
                int mid = (left + right) / 2;
                if (nums[mid] > nums[right])
                    left = mid + 1;
                else
                    right = mid;
            }
            return left;
        }

        int BS(vector<int> &nums, int left, int right, int target)
        {
            if (left <= right)
            {
                int mid = (left + right) / 2;
                if (nums[mid] == target)
                    return mid;
                if (nums[mid] > target)
                    return BS(nums, left, mid - 1, target);

                return BS(nums, mid + 1, right, target);
            }
            return  -1;
        }

        int search(vector<int> &nums, int target)
        {
            int pivot = minIndex(nums);
            int idxL = BS(nums, 0, pivot - 1, target);
            int idxR = BS(nums, pivot, nums.size() - 1, target);
            return max(idxL, idxR);
        }
};

