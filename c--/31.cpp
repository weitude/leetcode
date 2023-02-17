class Solution
{
    public:
        void nextPermutation(vector<int> &nums)
        {
            vector<int> temp;
            bool desc = true;
            int idx = nums.size() - 1;
            while (idx > 0)
            {
                temp.push_back(nums[idx]);
                if (nums[idx - 1] < nums[idx])
                {
                    desc = false;
                    idx--;
                    break;
                }
                idx--;
            }
            int target = nums[idx];
            temp.push_back(target);
            sort(temp.begin(), temp.end());
            if (desc)
                nums = temp;
            else
            {
                int larger = *upper_bound(temp.begin(), temp.end(), target);
                nums[idx] = larger;
                bool visit = false;
                for (int i = 0; i < temp.size(); i++)
                {
                    if (!visit && temp[i] == larger)
                    {
                        visit = true;
                        continue;
                    }
                    nums[++idx] = temp[i];
                }

            }

        }
};

