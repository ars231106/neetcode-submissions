class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int maxlength = 0;

        for(int i = 0; i<s.length(); i++){
            right = i;
            bool duplicate = false;

            for(int j = left; j<right; j++){
                if(s[j] == s[right]){
                    duplicate = true;
                    left = j + 1;
                    break;
                }
            }
            int count = right - left + 1;
            maxlength = max(maxlength, count); 
        }

        return maxlength;
    }
};
