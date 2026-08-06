class Solution {
public:
      vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> current;

    solve(candidates, 0, target, current, ans);

    return ans;
}

    void solve(vector<int>& nums,
           int index,
           int target,
           vector<int>& current,
           vector<vector<int>>& ans)
{
    // Base Cases
    if(target == 0)
    {
        ans.push_back(current);
        return;
    }

    if(target < 0)
        return;

    if(index == nums.size())
        return;

    // Choice 1 : Take
    current.push_back(nums[index]);

    solve(nums, index, target - nums[index], current, ans);

    // Undo
    current.pop_back();

    // Choice 2 : Don't Take
    solve(nums, index + 1, target, current, ans);
}
};