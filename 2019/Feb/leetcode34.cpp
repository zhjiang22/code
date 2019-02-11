class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        if (n == 0) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        if (nums[l] != target) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int ans1 = l;
        l = 0, r= n - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (nums[mid] <= target)
                l = mid;
            else
                r = mid - 1;
        }
        if (nums[l] != target) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int ans2 = l;
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};

