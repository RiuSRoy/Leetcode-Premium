class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int diff = 0, ans = 0, i = 0;
        unordered_map<char,int>m;
        for(int j = 0; j < s.length(); ++j) {
            if(m[s[j]] == 0) {
                ++diff;
            }
            m[s[j]]++;
            if(diff <= k) {
                ans = max(ans, j-i+1);
            } else {
                while(i <= j && diff > k) {
                    m[s[i]]--;
                    if(m[s[i]] == 0) {
                        --diff;
                    }
                    ++i;
                }
            }
        }
        return ans;
    }
};
