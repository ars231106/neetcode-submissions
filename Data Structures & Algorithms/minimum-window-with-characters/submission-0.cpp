class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> target;
        unordered_map<char, int> window;

        for (char c : t) {
            target[c]++;
        }

        int required = target.size();
        int formed = 0;

        int left = 0;
        int startIndex = 0;
        int minLength = INT_MAX;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            window[c]++;

            if (target.count(c) && window[c] == target[c]) {
                formed++;
            }

            while (formed == required) {
                int windowLength = right - left + 1;

                if (windowLength < minLength) {
                    minLength = windowLength;
                    startIndex = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                if (target.count(leftChar) &&
                    window[leftChar] < target[leftChar]) {
                    formed--;
                }

                left++;
            }
        }

        if (minLength == INT_MAX) {
            return "";
        }

        return s.substr(startIndex, minLength);
    }
};