class Solution {
public:
    vector<int> now;
    set<vector<int> > ss;
    void dfs(int cur, vector<vector<int> > &ans, vector<int> a, int n) {
        if (cur == n) {
            vector<int> v;
            v.assign(now.begin(), now.end());
            sort(v.begin(), v.end());
            if (!ss.count(v)) {
                ans.push_back(v);
                ss.insert(v);
            }
            return;
        }
        dfs(cur + 1, ans, a, n);
        now.push_back(a[cur]);
        dfs(cur + 1, ans, a, n);
        now.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > ans;
        dfs(0, ans, nums, n);
        return ans;
    }
};
