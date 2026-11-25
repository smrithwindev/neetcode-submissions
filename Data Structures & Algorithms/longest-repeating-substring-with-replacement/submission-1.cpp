class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int l = 0;
        unordered_map<char,int> Count;
        int maxFreq = 0;
        int maxLength = 0;

        for(int r=0; r< s.length(); r++)
        {
            Count[s[r]]++;

            maxFreq = max(maxFreq, Count[s[r]]);  // here only the count matters, don't matter if its A's or B's

            while((r-l+1) - maxFreq > k)
            {
                Count[s[l]]--;
                l++;
            }

            maxLength = max(maxLength, r - l + 1);
        }
        return maxLength;
    }
};