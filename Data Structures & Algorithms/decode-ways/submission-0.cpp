class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0 || s[0] == '0'){
            return 0;
        }

        vector<unsigned int> dp(s.length() + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i<=s.length(); i++){
            //for decoding as individual single digits
            if(s[i-1] != '0'){
                dp[i] = dp[i] + dp[i-1];
            }

            //for decoding as two digits
            int twodigits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if(twodigits >= 10 && twodigits <= 26){
                dp[i] = dp[i] + dp[i-2];
            }
        }
        return dp[s.length()];
    }
};