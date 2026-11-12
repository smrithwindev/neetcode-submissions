class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> result;
        for(const auto& s : strs)
        {
            string str = s;
            sort(str.begin(),str.end());
            result[str].push_back(s); 
        }
        vector<vector<string>> res;
        for(auto& pair : result)
        {
            res.push_back(pair.second);
        }
        return res;
    }
};
