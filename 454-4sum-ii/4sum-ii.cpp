class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B,
                 vector<int>& C, vector<int>& D)
{
    unordered_map<int, int> mp;
    int answer = 0;

    for(int i = 0; i < A.size(); i++)
    {
        for(int j = 0; j < B.size(); j++)
        {
            int sum = A[i] + B[j];
            mp[sum]++;
        }
    }

    for(int i = 0; i < C.size(); i++)
    {
        for(int j = 0; j < D.size(); j++)
        {
            int sum = C[i] + D[j];
            int needed = -sum;

            if(mp.count(needed))
                answer += mp[needed];
        }
    }

    return answer;
}
};