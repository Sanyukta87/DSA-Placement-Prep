class Solution {
public:
      void solve(vector<int>& nums,      // Original array
               vector<int>& current,     // Nothing chosen yet
               vector<vector<int>>& ans,     // No answer yet
               vector<bool>& visited)       // Nothing visited
               {
    // Base Case
    if(current.size() == nums.size())
    {
        ans.push_back(current);
        return;
    }

    for(int i = 0; i < nums.size(); i++)
    {
        if(visited[i])
            continue;

        // Choose
        current.push_back(nums[i]);
        visited[i] = true;

        // Explore
        solve(nums, current, ans, visited);

        // Undo
        current.pop_back();
        visited[i] = false;
    }
        }
        vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;                  // Final answer
        vector<int> current;                      // Current permutation
        vector<bool> visited(nums.size(), false); // Initially all unused

        solve(nums, current, ans, visited);

        return ans;
    }
};