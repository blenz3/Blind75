class Solution {
public:
    
    static const size_t FREQUENCY_MAP_LENGTH = 256;

    string minWindow(string s, string t) {
        int minLength(INT_MAX), bestLeftIdx(-1), bestRightIdx(-1);
        
        // Initialize character frequencies
        int sFreqs[FREQUENCY_MAP_LENGTH];
        int tFreqs[FREQUENCY_MAP_LENGTH];
        ::memset(&sFreqs, 0, sizeof sFreqs);
        ::memset(&tFreqs, 0, sizeof tFreqs);
        for (auto c : t) {
            tFreqs[static_cast<size_t>(c)]++;
        }
        
        int left = 0, right = 0, validCharactersRequired = t.length();
        for (; right < s.length(); ++right) {
            sFreqs[s[right]]++;
            
            // We've added a character we needed so we account for that character
            if (tFreqs[s[right]] != 0 && sFreqs[s[right]] <= tFreqs[s[right]]) 
                validCharactersRequired--;
            
            // Only continue when we have a match 
            if (validCharactersRequired != 0) {
                continue;
            }
            
            // Truncate the window left until we no longer have a match. We know when the match
            // is no longer good because at least one frequency count will have a greater t frequency
            // than the s frequency
            while (tFreqs[s[left]] == 0 || sFreqs[s[left]] > tFreqs[s[left]]) {
                sFreqs[s[left]]--;
                left++;
            }
            
            // When we do have a valid substring we capture the potential result 
            if (minLength > right - left  + 1) {
                // minSubstring = s.substr(left, right - left + 1);
                minLength = right - left + 1;
                bestLeftIdx = left;
                bestRightIdx = right;
            }
            
        }
        
        return (bestLeftIdx != -1) ? s.substr(bestLeftIdx, bestRightIdx - bestLeftIdx + 1) : "";
    }
};
