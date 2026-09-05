class Solution {
public:
    int findSpecialInteger(vector<int>& nums)  //fux
{
    unordered_map<int, int> mp;

    for(int x : nums)
        mp[x]++;

    for(auto p : mp)
    {
        if(p.second > nums.size() / 4)
            return p.first;
    }

    return -1;
}
};