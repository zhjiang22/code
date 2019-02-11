class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = 0;
        int l = nums.size();
        if (l == 0) return 0;
        for (int i = 1; i < l; i++) {
            if (nums[i] != nums[cur]) {
                nums[++cur] = nums[i];
            }
        }
        return cur;
    }
};
