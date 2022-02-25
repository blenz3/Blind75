class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() < 2) {
            return s.length();
        }
        
        int characters[256];
        ::memset(&characters, 0, sizeof characters);
        
        int currentMax(0);
        int begin = 0, end = begin;
        while (end < s.length()) {
            size_t characterIdx = static_cast<size_t>(s[end]);
            // No duplicate introduced let's just move forward on our way
            if (characters[characterIdx] == 0) {
                characters[characterIdx]++;
                currentMax = std::max(currentMax, end - begin + 1);
                end++;
                continue;
            } 
            
            // Duplicate discoved so move the begin pointer to the first occurrence of the duplicate
            while (s[begin] != s[end]) {
                characters[static_cast<size_t>(s[begin])]--;
                begin++;
            }
            
            // Now that we've moved to the duplicate let's account for the removal
            // of the character and scoot our pointers over 1
            characters[static_cast<size_t>(s[begin])] = 1;
            begin++;
            end++;
            
        }
        
        return currentMax;
    }
};
