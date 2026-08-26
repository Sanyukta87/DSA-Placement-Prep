class Solution {
public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    unordered_set<int> st;

    for(int x : nums1)
        st.insert(x);

    vector<int> answer;

    for(int x : nums2)
    {
        if(st.count(x))
        {
            answer.push_back(x);
            st.erase(x);
        }
    }

    return answer;
    }
};