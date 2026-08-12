class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        stack<int> st;
        unordered_map<int, int> ans; //map

        // Process nums2 from left to right
        for(int num : nums2)
        {
            // Current num is greater than stack top
            // → num is the next greater element
            while(!st.empty() && st.top() < num)
            {
                ans[st.top()] = num;
                st.pop();
            }

           st.push(num);  // Current num hasn't found its answer yet
        }

        while(!st.empty())  // Remaining elements have no greater element
        {
            ans[st.top()] = -1;
            st.pop();
        }

        // Build answer for nums1 using the map
        vector<int> result;

        for(int num : nums1)
        {
            result.push_back(ans[num]);
        }

        return result;
    }
};