using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int i = 0, j = 0, length = s.size();
      unordered_set<int> session;
      int maxLen = 0;
      while (i < length && j < length) {
        if (session.find(s[j]) == session.end()) {
          session.insert(s[j++]);
          maxLen = maxLen > j - i ? maxLen : j - i;
        } else {
          session.erase(s[i++]);
        }
      }
      return maxLen;
    }
};
