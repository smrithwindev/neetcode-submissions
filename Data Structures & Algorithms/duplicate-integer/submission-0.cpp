class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> MySet;
        for(int num : nums)
        {
            if(!MySet.count(num))
            {
                MySet.insert(num);
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};