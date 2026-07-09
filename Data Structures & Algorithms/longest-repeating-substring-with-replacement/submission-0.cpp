class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>freq;
        
        int maxfreq = 0;
        int left = 0;
        int maxlength = 0;

        for(int right = 0; right<s.length(); right++){
            freq[s[right]]++;

            maxfreq = max(maxfreq, freq[s[right]]);

            int windowlength = right - left + 1;

            if(windowlength - maxfreq > k){
                freq[s[left]]--;
                left++;
            }

            windowlength = right - left + 1;
            maxlength = max(maxlength, windowlength);
        }

        return maxlength;
    }
};
