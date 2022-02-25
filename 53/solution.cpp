class Solution {
public:
    // Use a constant size array to check if every character in s is actually  in t
    bool isAnagram(string s, string t) {
        
        if (s.size() != t.size()) {
            return false;
        }
        
        int characters[256];
        ::memset(&characters, 0, sizeof characters);
        
        // iterate each character of s increment the corresponding character 
        for (int i = 0; i < s.size(); ++i) {
            characters[static_cast<size_t>(s[i])]++;
        }
        
        // iterate each character of t and decrement the corresponding character
        for (int i = 0; i < t.size(); ++i) {
            characters[static_cast<size_t>(t[i])]--;
        }
        
        // if any character count is non zero then they aren't anagrams
        for (int i = 0; i < sizeof characters / sizeof(int); ++i) {
            if (characters[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
};
