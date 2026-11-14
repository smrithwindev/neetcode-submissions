class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> freq(nums.size() + 1);
        unordered_map<int,int> result;
        for(int i=0; i<nums.size();i++)
        {
            result[nums[i]]++;
        }
        for(const auto& entry : result)
        {
            freq[entry.second].push_back(entry.first);
        }
        vector<int> res;
        for(int i = freq.size()-1; i>0 ;i--)
        {
            for(int n : freq[i])
            {
                res.push_back(n);

                    if(res.size() == k)
                    {
                        return res;
                    }
            }
        }
        return res;
    }
};