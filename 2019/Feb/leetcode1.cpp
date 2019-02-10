class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        set<int> s;
        int l = nums.size();
        for (int i = l - 1; i >= 0; i--) {
            if (s.count(target - nums[i]))
                ans.push_back(i);
            s.insert(nums[i]);
        }
        s.clear();
        for (int i = 0; i < l; i++) {
            if (s.count(target - nums[i]))
                ans.push_back(i);
            s.insert(nums[i]);
        }
        return ans;
    }
};
