class Solution {
public:
    string minWindow(string s, string t) {
      unordered_map<char, int> countT, window;

      
      for(char c : t)
      {
        countT[c]++;
      }

      int have = 0;     // 
      int need = countT.size();

      int resStart = 0;   // starting index of the valid substring so far
      int resLen = INT_MAX; // current size of the valid substring so far 

      int l = 0;

      for(int r = 0; r< s.length(); r++)
      {

        char c = s[r];

        window[c]++;

        if(countT.count(c) && window[c] == countT[c]) // in the 2nd condition   we are checking whether both maps have the same count for the current character
        {
            have++;
        }

        while(have == need)
        {
            if(r-l+1 < resLen)
            {
                resStart = l;
                resLen = r - l + 1;
            }

            window[s[l]]--;

            if(countT.count(s[l]) && window[s[l]] < countT[s[l]])
            {
                have--;
            }

            l++;
        }
    }
        if(resLen == INT_MAX)
        {
            return "";
        }

      return s.substr(resStart, resLen);
      
    }
};